--- src/cvrstgfile.cc.orig	Thu Sep 26 21:57:20 2002
+++ src/cvrstgfile.cc	Thu Sep 26 22:06:43 2002
@@ -20,7 +20,8 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <string.h>
+#include <string>
+#include <vector>
 #include <assert.h>
 
 #include <libintl.h>
@@ -106,7 +107,7 @@
 }
 
 /* 'creates' a stego file from a cover file */
-void CvrStgFile::transform (string stgfn)
+void CvrStgFile::transform (std::string stgfn)
 {
 	delete getBinIO() ;
 	setBinIO (new BinaryIO (stgfn, BinaryIO::WRITE)) ;
@@ -144,7 +145,7 @@
 	return retval ;
 }
 
-CvrStgFile* CvrStgFile::readfile (string fn)
+CvrStgFile* CvrStgFile::readfile (std::string fn)
 {
 	BinaryIO *BinIO = new BinaryIO (fn, BinaryIO::READ) ;
 
