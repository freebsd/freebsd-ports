--- src/aufile.cc.orig	Thu Sep 26 22:51:50 2002
+++ src/aufile.cc	Thu Sep 26 22:54:09 2002
@@ -23,6 +23,7 @@
 #include <cstdlib>
 #include <cstring>
 #include <vector>
+#include <string>
 
 #include <libintl.h>
 #define _(S) gettext (S)
@@ -51,12 +52,12 @@
 {
 }
 
-vector<unsigned char> AuFile::getData (void)
+std::vector<unsigned char> AuFile::getData (void)
 {
 	return data ;
 }
 
-void AuFile::setData (vector<unsigned char> d)
+void AuFile::setData (std::vector<unsigned char> d)
 {
 	data = d ;
 }
@@ -236,7 +237,7 @@
 void AuFile::writedata (void)
 {
 	try {
-		for (vector<unsigned char>::iterator i = data.begin() ; i != data.end() ; i++) {
+		for (std::vector<unsigned char>::iterator i = data.begin() ; i != data.end() ; i++) {
 			getBinIO()->write8 (*i) ;
 		}
 	}
