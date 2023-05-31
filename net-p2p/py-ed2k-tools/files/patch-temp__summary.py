--- temp_summary.py.orig	2003-05-06 11:53:14 UTC
+++ temp_summary.py
@@ -1,12 +1,9 @@
 #!/usr/bin/python
 from ed2k_metutils import *
 import os
-import stat
+import unicodedata
 
-# I'm really surprised there's no easy way to get the terminal
-# width in python... :-/  I can't do external invocations to
-# stty, etc, because they might not be there on windows... 
-WIDTH = 80;
+WIDTH = getattr(os.get_terminal_size(), 'columns', 80)
 
 if __name__ == "__main__":
 	# Here's an example to cut and keep.
@@ -15,26 +12,22 @@ if __name__ == "__main__":
 	# see how much data I actually got from night to night.
 	
 	if len( sys.argv ) < 2:
-		print "invocation: %s < <x.part.met> [x.part.met ...] | <temp_dir> >" % sys.argv[ 0 ];
-		print
-		print "This program will show the amount downloaded vs. the total size "
-		print "for the .part.met files listed on the command line." 
-		print
-		print "This program assumes an 80 column display.  You can tweak this "
-		print "by editing the script.  Change the 'WIDTH' value."
+		print("invocation: %s < <x.part.met> [x.part.met ...] | <temp_dir> >" % sys.argv[0])
+		print()
+		print("This program will show the amount downloaded vs. the total size")
+		print("for the .part.met files listed on the command line.")
 		sys.exit( -1 );
 	
 	total_size = total_down = 0;
 	
-	sta = os.stat( sys.argv[ 1 ] )[ 0 ];
-	if stat.S_ISDIR( sta ):
-		mets = [ "%s%s" % ( sys.argv[ 1 ], x ) for x in os.listdir( sys.argv[ 1 ] ) if x.endswith( ".met" ) ];
+	if os.path.isdir(sys.argv[1]):
+		mets = [ "%s/%s" % (sys.argv[1], x) for x in os.listdir(sys.argv[1]) if x.endswith(".met") ]
 	else:
 		mets = sys.argv[ 1 : ];
 	
 	for met_file in mets:
 		
-		fh = open( met_file, "r" );
+		fh = open(met_file, "rb")
 		data = fh.read();
 		fh.close();
 		
@@ -43,7 +36,7 @@ if __name__ == "__main__":
 		
 		# We're interested in the name, the total size, and some kind of... anti-gapping.
 		size = met_data.FindTags( TAG_HANDLE_FILESIZE )[ 0 ].value;
-		name = met_data.FindTags( TAG_HANDLE_FILENAME )[ 0 ].value;
+		name = met_data.FindTags(TAG_HANDLE_FILENAME)[0].value.decode()
 		
 		# Set the total downloaded to the file size.
 		down = size;
@@ -71,19 +64,42 @@ if __name__ == "__main__":
 		bar = "#" * ( WIDTH - 2 );
 		for gap in gaps:
 			gap_start, gap_end = gaps[ gap ];
-			char_gap_start = gap_start / bytes_per_char;
-			char_gap_end = gap_end / bytes_per_char;
+			char_gap_start = int(gap_start / bytes_per_char)
+			char_gap_end = int(gap_end / bytes_per_char)
 			bar = bar[ : char_gap_start ] + " " * ( char_gap_end - char_gap_start ) + bar[ char_gap_end : ];
+
+		# Account for CJK characters occupy two fixed-width spaces.
+		def char_width(c: str) -> int:
+			if not c.isprintable(): return 0
+			return 2 if unicodedata.category(c) == 'Lo' else 1
+
+		def visible_len(s: str) -> int:
+			return sum(char_width(c) for c in s)
+
+		# Truncate string to specified limit.  If truncation happens
+		# on double-width character (like it would have to be cut in
+		# half), append an extra space for nicer alignment.
+		def visible_substr_padded(s: str, l: int) -> str:
+			vislen = 0
+			cut_here = 0
+			padding = ''
+			for c in s:
+				vislen += char_width(c)
+				if vislen <= l: cut_here += 1
+				if vislen == l: break
+				if vislen > l: padding = ' '; break
+			return s[:cut_here] + padding
 				
 		# Print out our summary.  Limit the filenames.
-		sizestring = " - %s - %iK of %iK" % ( met_file.split( "/" )[ -1 ], down / 1024, size / 1024 );
+		sizestring = " - %s - %.2fK of %.2fK" % (met_file.split("/")[-1], down / 1024, size / 1024)
 		max_name_size = WIDTH - len( sizestring );
-		if len( name ) < max_name_size:
-			name += " " * ( max_name_size - len( name ) );
+		vislen = visible_len(name)
+		if vislen < max_name_size:
+			name += " " * (max_name_size - vislen)
 		else:
-			name = name[ : max_name_size ];
-		print "%s%s" % ( name, sizestring );
-		print "[%s]" % bar;
-		print 
+			name = visible_substr_padded(name, max_name_size)
+		print("%s%s" % (name, sizestring))
+		print("[%s]" % bar)
+		print()
 		del( met_data );
-	print "Totals: %sK of %sK" % ( total_down / 1024, total_size / 1024 );
+	print("Totals: %.2fK of %.2fK" % (total_down / 1024, total_size / 1024))
