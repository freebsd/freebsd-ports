--- src/binaryio.cc.orig	Mon May 13 22:48:06 2002
+++ src/binaryio.cc	Thu Jul 17 14:27:14 2003
@@ -20,6 +20,7 @@
 
 #include <stdio.h>
 #include <sstream>
+#include <assert.h>
 
 #include <libintl.h>
 #define _(S) gettext (S)
@@ -37,7 +38,7 @@
 	set_open (false) ;
 }
 
-BinaryIO::BinaryIO (string fn, MODE m)
+BinaryIO::BinaryIO (std::string fn, MODE m)
 {
 	BinaryIO () ;
 	open (fn, m) ;
@@ -60,12 +61,12 @@
 	stream = s ;
 }
 
-string BinaryIO::getName (void)
+std::string BinaryIO::getName (void)
 {
 	return filename ;
 }
 
-void BinaryIO::setName (string fn)
+void BinaryIO::setName (std::string fn)
 {
 	filename = fn ;
 }
@@ -95,7 +96,7 @@
 	mode = m ;
 }
 
-void BinaryIO::open (string fn, MODE m)
+void BinaryIO::open (std::string fn, MODE m)
 {
 	if (fn == "") {
 		switch (m) {
@@ -243,9 +244,9 @@
 	return ((bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3]) ;
 }
 
-string BinaryIO::readstring (unsigned int len)
+std::string BinaryIO::readstring (unsigned int len)
 {
-	ostringstream ost ;
+	std::ostringstream ost ;
 	for (unsigned int i = 0 ; i < len ; i++) {
 		ost << read8() ;
 	}
@@ -310,7 +311,7 @@
 	}
 }
 
-void BinaryIO::writestring (string s)
+void BinaryIO::writestring (std::string s)
 {
 	if (fputs (s.c_str(), getStream()) == EOF) {
 		throw BinaryOutputError (getName()) ;
