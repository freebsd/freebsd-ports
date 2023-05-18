--- temp_summary.py.orig	2003-05-06 11:53:14 UTC
+++ temp_summary.py
@@ -15,13 +15,13 @@ if __name__ == "__main__":
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
+		print()
+		print("This program assumes an 80 column display.  You can tweak this")
+		print("by editing the script.  Change the 'WIDTH' value.")
 		sys.exit( -1 );
 	
 	total_size = total_down = 0;
@@ -34,7 +34,7 @@ if __name__ == "__main__":
 	
 	for met_file in mets:
 		
-		fh = open( met_file, "r" );
+		fh = open(met_file, "rb")
 		data = fh.read();
 		fh.close();
 		
@@ -71,19 +71,19 @@ if __name__ == "__main__":
 		bar = "#" * ( WIDTH - 2 );
 		for gap in gaps:
 			gap_start, gap_end = gaps[ gap ];
-			char_gap_start = gap_start / bytes_per_char;
-			char_gap_end = gap_end / bytes_per_char;
+			char_gap_start = int(gap_start / bytes_per_char)
+			char_gap_end = int(gap_end / bytes_per_char)
 			bar = bar[ : char_gap_start ] + " " * ( char_gap_end - char_gap_start ) + bar[ char_gap_end : ];
 				
 		# Print out our summary.  Limit the filenames.
-		sizestring = " - %s - %iK of %iK" % ( met_file.split( "/" )[ -1 ], down / 1024, size / 1024 );
+		sizestring = " - %s - %.2fK of %.2fK" % (met_file.split("/")[-1], down / 1024, size / 1024)
 		max_name_size = WIDTH - len( sizestring );
 		if len( name ) < max_name_size:
-			name += " " * ( max_name_size - len( name ) );
+			name += b" " * (max_name_size - len(name))
 		else:
 			name = name[ : max_name_size ];
-		print "%s%s" % ( name, sizestring );
-		print "[%s]" % bar;
-		print 
+		print("%s%s" % (name.decode(), sizestring))
+		print("[%s]" % bar)
+		print()
 		del( met_data );
-	print "Totals: %sK of %sK" % ( total_down / 1024, total_size / 1024 );
+	print("Totals: %.2fK of %.2fK" % (total_down / 1024, total_size / 1024))
