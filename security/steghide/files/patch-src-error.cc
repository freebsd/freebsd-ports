--- src/error.cc.orig	Thu Sep 26 22:57:49 2002
+++ src/error.cc	Thu Sep 26 23:01:15 2002
@@ -37,7 +37,7 @@
 {
 }
 
-SteghideError::SteghideError(string msg)
+SteghideError::SteghideError(std::string msg)
 	: MessageBase(msg)
 {
 }
@@ -53,13 +53,13 @@
 
 void SteghideError::printMessage (void)
 {
-	cerr << PROGNAME << ": " << getMessage() << endl ;
+	std::cerr << PROGNAME << ": " << getMessage() << std::endl ;
 }
 
 //
 // class BinaryInputError
 //
-BinaryInputError::BinaryInputError (string fn, FILE* s)
+BinaryInputError::BinaryInputError (std::string fn, FILE* s)
 	: SteghideError()
 {
 	if (feof (s)) {
@@ -97,7 +97,7 @@
 //
 // class BinaryOutputError
 //
-BinaryOutputError::BinaryOutputError (string fn)
+BinaryOutputError::BinaryOutputError (std::string fn)
 	: SteghideError()
 {
 	if (fn == "") {
@@ -142,12 +142,12 @@
 {
 	va_list ap ;
 	va_start (ap, msgfmt) ;
-	string auxmsg = vcompose (msgfmt, ap) ;
+	std::string auxmsg = vcompose (msgfmt, ap) ;
 	va_end (ap) ;
 
-	string mainmsg ;
+	std::string mainmsg ;
 	if (io->is_std()) {
-		mainmsg = string (_("corrupt jpeg file on standard input:")) ;
+		mainmsg = std::string (_("corrupt jpeg file on standard input:")) ;
 	}
 	else {
 		mainmsg = compose (_("corrupt jpeg file \"%s\":"), io->getName().c_str()) ;
