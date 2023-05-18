--- make_met.py.orig	2003-05-06 11:53:14 UTC
+++ make_met.py
@@ -7,14 +7,13 @@ import re
 if __name__ == "__main__":
 	
 	if len( sys.argv ) < 3:
-		print "invocation: %s <temp-directory> <ed2k://...>" % sys.argv[ 0 ];
-		print ;
-		print "This script creates a new .part.met file in the directory of the first";
-		print "argument, which represents the ed2k:// link provided as the second arg.";
-		print ;
-		print "Useful for adding things to your download list without actually opening ";
-		print "Overnet / Donkey.";
-		print ;
+		print("invocation: %s <temp-directory> <ed2k://...>" % sys.argv[0])
+		print()
+		print("This script creates a new .part.met file in the directory of the first")
+		print("argument, which represents the ed2k:// link provided as the second arg.")
+		print()
+		print("Useful for adding things to your download list without actually opening")
+		print("Overnet / Donkey.")
 		sys.exit( -1 );
 	
 	temp_dir = sys.argv[ 1 ];
@@ -25,9 +24,9 @@ if __name__ == "__main__":
 	matches = ed2k_reg.findall( ed2k_link );
 	
 	if not matches:
-		print "Oh no!  This ( %s ) doesn't feel like an ed2k link!" % ( ed2k_link );
-		print "ed2k file links have the form:";
-		print "   ed2k://|file|<file name>|<file size>|<md4 hash>|";
+		print("Oh no!  This (%s) doesn't look like an ed2k link!" % (ed2k_link))
+		print("ed2k file links have the form:")
+		print("  ed2k://|file|<file name>|<file size>|<md4 hash>|")
 		sys.exit( -1 );
 	
 	name, size, hash = ed2k_reg.findall( ed2k_link )[ 0 ];
@@ -35,11 +34,11 @@ if __name__ == "__main__":
 
 	# Convert the printed hash into a byte representation.
 	# Surely there's an easier way to do this.
-	new_hash = "";	
+	new_hash = b''
 	while hash:
 		part = hash[ 0 : 2 ];
 		hash = hash[ 2 : ];
-		new_hash += chr( eval( "0x" + part ) );
+		new_hash += bytes([eval("0x" + part)])
 
 	# Find the first unused download identifier.
 	metfiles = [ int( x.split( "." )[ 0 ] ) for x in os.listdir( temp_dir ) if x.endswith( ".part.met" ) ];
@@ -53,22 +52,22 @@ if __name__ == "__main__":
 	# Build the structure.
 	new = MetFile();
 	new.fileID = new_hash;
-	new.AddTag( MetaTag( TAG_HANDLE_FILENAME, name ) );
+	new.AddTag(MetaTag(TAG_HANDLE_FILENAME, name.encode()))
 	new.AddTag( MetaTag( TAG_HANDLE_FILESIZE, size ) );	
 	new.AddTag( MetaTag( TAG_HANDLE_SOFAR, 0 ) );
 	# Now, I thought this implied an off-by-one error ( if a file is
 	# five bytes long, the gap should go from byte 0 to byte 4... ),
 	# but apparently that's not how we do it here.
-	new.AddTag( MetaTag( "%s0" % TAG_HANDLE_GAP_START, 0 ) );
-	new.AddTag( MetaTag( "%s0" % TAG_HANDLE_GAP_END, size ) );
+	new.AddTag(MetaTag(b"%s0" % TAG_HANDLE_GAP_START, 0))
+	new.AddTag(MetaTag(b"%s0" % TAG_HANDLE_GAP_END, size))
 	new.AddTag( MetaTag( TAG_HANDLE_PAUSED, 0 ) );
 	new.AddTag( MetaTag( TAG_HANDLE_PRIORITY, 1 ) );
 
 	# Write it out.
-	fh = open( filename, "w" );
+	fh = open(filename, "wb")
 	fh.write( new.ReduceToData() );
 	fh.close();
 
 	del( new );
 
-	print "Wrote met for %s to %s." % ( ed2k_link, filename );	
+	print("Wrote met for %s to %s." % (ed2k_link, filename))
