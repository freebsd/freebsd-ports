--- src/msg.cc.orig	Thu Sep 26 22:42:25 2002
+++ src/msg.cc	Thu Sep 26 22:49:08 2002
@@ -22,6 +22,7 @@
 #include <cstdarg>
 #include <cstdio>
 #include <iostream>
+#include <string>
 
 #include <termios.h>
 
@@ -41,7 +42,7 @@
 	setMessage (_("__no_message_defined__")) ;
 }
 
-MessageBase::MessageBase (string msg)
+MessageBase::MessageBase (std::string msg)
 {
 	setMessage (msg) ;
 }
@@ -58,12 +59,12 @@
 {
 }
 
-string MessageBase::getMessage ()
+std::string MessageBase::getMessage ()
 {
 	return message ;
 }
 
-void MessageBase::setMessage (string msg)
+void MessageBase::setMessage (std::string msg)
 {
 	message = msg ;
 }
@@ -76,20 +77,20 @@
 	va_end (ap) ;
 }
 
-string MessageBase::compose (const char *msgfmt, ...)
+std::string MessageBase::compose (const char *msgfmt, ...)
 {
 	va_list ap ;
 	va_start (ap, msgfmt) ;
-	string retval = vcompose (msgfmt, ap) ;
+	std::string retval = vcompose (msgfmt, ap) ;
 	va_end (ap) ;
 	return retval ;
 }
 
-string MessageBase::vcompose (const char *msgfmt, va_list ap)
+std::string MessageBase::vcompose (const char *msgfmt, va_list ap)
 {
 	char *str = new char[MsgMaxSize] ;
 	vsnprintf (str, MsgMaxSize, msgfmt, ap) ;
-	return string (str) ;
+	return std::string (str) ;
 }
 
 //
@@ -109,7 +110,7 @@
 	if (args->verbosity.getValue() == NORMAL ||
 		args->verbosity.getValue() == VERBOSE) {
 
-		cerr << getMessage() << endl ;
+		std::cerr << getMessage() << std::endl ;
 	}
 }
 
@@ -128,7 +129,7 @@
 void VerboseMessage::printMessage ()
 {
 	if (args->verbosity.getValue() == VERBOSE) {
-		cerr << getMessage() << endl ;
+		std::cerr << getMessage() << std::endl ;
 	}
 }
 
@@ -149,7 +150,7 @@
 	if (args->verbosity.getValue() == NORMAL ||
 		args->verbosity.getValue() == VERBOSE) {
 
-		cerr << PROGNAME << _(": warning: ") << getMessage() << endl ;
+		std::cerr << PROGNAME << _(": warning: ") << getMessage() << std::endl ;
 	}
 }
 
@@ -167,7 +168,7 @@
 
 void CriticalWarning::printMessage ()
 {
-	cerr << PROGNAME << _(": warning: ") << getMessage() << endl ;
+	std::cerr << PROGNAME << _(": warning: ") << getMessage() << std::endl ;
 }
 
 //
@@ -176,22 +177,22 @@
 Question::Question (void)
 	: MessageBase()
 {
-	yeschar = string (_("y")) ;
-	nochar = string (_("n")) ;
+	yeschar = std::string (_("y")) ;
+	nochar = std::string (_("n")) ;
 }
 
-Question::Question (string msg)
+Question::Question (std::string msg)
 	: MessageBase (msg)
 {
-	yeschar = string (_("y")) ;
-	nochar = string (_("n")) ;
+	yeschar = std::string (_("y")) ;
+	nochar = std::string (_("n")) ;
 }
 
 Question::Question (const char *msgfmt, ...)
 	: MessageBase()
 {
-	yeschar = string (_("y")) ;
-	nochar = string (_("n")) ;
+	yeschar = std::string (_("y")) ;
+	nochar = std::string (_("n")) ;
 
 	va_list ap ;
 	va_start (ap, msgfmt) ;
@@ -203,7 +204,7 @@
 {
 	assert (!stdin_isused()) ;
 
-	cerr << getMessage() << " (" << yeschar << "/" << nochar << ") " ;
+	std::cerr << getMessage() << " (" << yeschar << "/" << nochar << ") " ;
 }
 
 bool Question::getAnswer ()
@@ -212,11 +213,11 @@
 
 	struct termios oldattr = termios_singlekey_on () ;
 	char input[2] ;
-	input[0] = cin.get() ;
+	input[0] = std::cin.get() ;
 	input[1] = '\0' ;
-	bool retval = (string (input) == yeschar) ;
+	bool retval = (std::string (input) == yeschar) ;
 	termios_reset (oldattr) ;
 
-	cerr << endl ;
+	std::cerr << std::endl ;
 	return retval ;
 }
