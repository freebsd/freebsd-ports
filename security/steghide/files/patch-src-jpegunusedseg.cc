--- src/jpegunusedseg.cc.orig	Thu Sep 26 23:45:27 2002
+++ src/jpegunusedseg.cc	Thu Sep 26 23:47:31 2002
@@ -19,6 +19,7 @@
  */
 
 #include <vector>
+#include <string>
 
 #include "binaryio.h"
 #include "jpegbase.h"
@@ -56,7 +57,7 @@
 void JpegUnusedSegment::write (BinaryIO *io)
 {
 	JpegSegment::write (io) ;
-	for (vector<unsigned char>::iterator i = data.begin() ; i != data.end() ; i++) {
+	for (std::vector<unsigned char>::iterator i = data.begin() ; i != data.end() ; i++) {
 		io->write8 (*i) ;
 	}
 }
