--- src/binaryio.cc.orig	Thu Sep 26 19:38:01 2002
+++ src/binaryio.cc	Thu Sep 26 19:47:54 2002
@@ -37,7 +37,7 @@
 	set_open (false) ;
 }
 
-BinaryIO::BinaryIO (string fn, MODE m)
+BinaryIO::BinaryIO (std::string fn, MODE m)
 {
 	BinaryIO () ;
 	open (fn, m) ;
@@ -60,12 +60,12 @@
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
@@ -95,7 +95,7 @@
 	mode = m ;
 }
 
-void BinaryIO::open (string fn, MODE m)
+void BinaryIO::open (std::string fn, MODE m)
 {
 	if (fn == "") {
 		switch (m) {
@@ -243,9 +243,9 @@
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
@@ -310,7 +310,7 @@
 	}
 }
 
-void BinaryIO::writestring (string s)
+void BinaryIO::writestring (std::string s)
 {
 	if (fputs (s.c_str(), getStream()) == EOF) {
 		throw BinaryOutputError (getName()) ;
