--- retrieve_link.py.orig	2003-05-06 11:53:14 UTC
+++ retrieve_link.py
@@ -8,22 +8,21 @@ if __name__ == "__main__":
 	# you break one so badly all you want back is the ed2k:// hash.
 	
 	if len( sys.argv ) < 2:
-		print "invocation: %s <x.part.met> [x.part.met ...]" % sys.argv[ 0 ];
-		print
-		print "This program will print out the ed2k:// link responsible for"
-		print "the formation of a given .part.met file or files, given on "
-		print "the command line."
-		print
+		print("invocation: %s <x.part.met> [x.part.met ...]" % sys.argv[0])
+		print()
+		print("This program will print out the ed2k:// link responsible for")
+		print("the formation of a given .part.met file or files, given on")
+		print("the command line.")
 		sys.exit( -1 );
 	
 	for met_file in sys.argv[ 1 : ]:
 		
-		fh = open( met_file, "r" );
+		fh = open(met_file, "rb")
 		data = fh.read();
 		fh.close();
 		
 		met_data = MetFile( data );
 		del( data );
 		
-		print "%s: %s" % ( met_file, met_data.getEd2K() );
+		print("%s: %s" % (met_file, met_data.getEd2K()))
 		del( met_data );
