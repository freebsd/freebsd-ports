--- fix_sofar.py.orig	2003-05-06 11:53:14 UTC
+++ fix_sofar.py
@@ -11,26 +11,25 @@ if __name__ == "__main__":
 	# This will undo the damage.
 	
 	if len( sys.argv ) < 2:
-		print "invocation: %s <x.part.met> [x.part.met ...]" % sys.argv[ 0 ];
-		print
-		print "Some versions of Overnet on MacOSX seem not to write the 0x08 'sofar' tag"
-		print "on exiting, this gives the appearance that the next time you boot overnet,"
-		print "nothing has been downloaded.  It's only cosmetic, however."
-		print
-		print "If you want to create new .met files with this 'bug' corrected, run this"
-		print "program with the affected .met files as the command line arguments.  You"
-		print "will get new .met files titled X.new, where X was the original .part.met"
-		print "file.  Copy these over the top of your originals if you're sure thats what"
-		print "you want to do."
-		print
-		print "Of course, Overnet will re-break these files on its next exit.  You'll"
-		print "need to run this program a lot to keep everything setup."
-		print
+		print("invocation: %s <x.part.met> [x.part.met ...]" % sys.argv[0])
+		print()
+		print("Some versions of Overnet on MacOSX seem not to write the 0x08 'sofar' tag")
+		print("on exiting, this gives the appearance that the next time you boot overnet,")
+		print("nothing has been downloaded.  It's only cosmetic, however.")
+		print()
+		print("If you want to create new .met files with this 'bug' corrected, run this")
+		print("program with the affected .met files as the command line arguments.  You")
+		print("will get new .met files titled X.new, where X was the original .part.met")
+		print("file.  Copy these over the top of your originals if you're sure that's what")
+		print("you want to do.")
+		print()
+		print("Of course, Overnet will re-break these files on its next exit.  You'll")
+		print("need to run this program a lot to keep everything setup.")
 		sys.exit( -1 );
 	
 	for met_file in sys.argv[ 1 : ]:
 		
-		fh = open( met_file, "r" );
+		fh = open(met_file, "rb")
 		data = fh.read();
 		fh.close();
 		
@@ -55,14 +54,14 @@ if __name__ == "__main__":
 		for gap in gaps.keys():
 			so_far -= gaps[ gap ];
 		
-		print "%s: %s" % ( met_file, met_data.FindTags( TAG_HANDLE_FILENAME )[ 0 ].value );
-		print "MD4: %s" % ( met_data.getMD4() );
-		print "Obtained size / total: %i / %i" % ( so_far, length );
+		print("%s: %s" % (met_file, met_data.FindTags(TAG_HANDLE_FILENAME)[0].value.decode()))
+		print("MD4: %s" % met_data.getMD4())
+		print("Obtained size / total: %i / %i" % (so_far, length))
 		
 		met_data.PurgeTags( TAG_HANDLE_SOFAR );
 		met_data.AddTag( MetaTag( TAG_HANDLE_SOFAR, so_far, TAG_TYPE_INTEGER ) );
 			
-		fh = open( "%s.new" % met_file, "w" );
+		fh = open("%s.new" % met_file, "wb")
 		fh.write( met_data.ReduceToData() );
 		fh.close();
 		del( met_data );
