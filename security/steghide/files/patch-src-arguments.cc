--- src/arguments.cc.orig	Thu Sep 26 21:38:44 2002
+++ src/arguments.cc	Thu Sep 26 21:44:01 2002
@@ -19,6 +19,7 @@
  */
 
 #include <iostream>
+#include <string>
 
 #include <libintl.h>
 #define _(S) gettext (S)
@@ -53,15 +54,15 @@
 		command.setValue (SHOWHELP) ;
 		return ;
 	}
-	else if (string (argv[1]) == "embed" || string (argv[1]) == "--embed") {
+	else if (std::string (argv[1]) == "embed" || std::string (argv[1]) == "--embed") {
 		command.setValue (EMBED) ;
 		setDefaults () ;
 	}
-	else if (string (argv[1]) == "extract" || string (argv[1]) == "--extract") {
+	else if (std::string (argv[1]) == "extract" || std::string (argv[1]) == "--extract") {
 		command.setValue (EXTRACT) ;
 		setDefaults () ;
 	}
-	else if (string (argv[1]) == "version" || string (argv[1]) == "--version") {
+	else if (std::string (argv[1]) == "version" || std::string (argv[1]) == "--version") {
 		command.setValue (SHOWVERSION) ;
 		if (argc > 2) {
 			Warning w (_("you cannot use arguments with the \"version\" command")) ;
@@ -69,7 +70,7 @@
 		}
 		return ;
 	}
-	else if (string (argv[1]) == "license" || string (argv[1]) == "--license") {
+	else if (std::string (argv[1]) == "license" || std::string (argv[1]) == "--license") {
 		command.setValue (SHOWLICENSE) ;
 		if (argc > 2) {
 			Warning w (_("you cannot use arguments with the \"license\" command")) ;
@@ -77,7 +78,7 @@
 		}
 		return ;
 	}
-	else if (string (argv[1]) == "help" || string (argv[1]) == "--help") {
+	else if (std::string (argv[1]) == "help" || std::string (argv[1]) == "--help") {
 		command.setValue (SHOWHELP) ;
 		if (argc > 2) {
 			Warning w (_("you cannot use arguments with the \"help\" command")) ;
@@ -86,7 +87,7 @@
 		return ;
 	}
 #ifdef DEBUG
-	else if (string (argv[1]) == "test") {
+	else if (std::string (argv[1]) == "test") {
 		steghide_test_all () ;
 		exit (EXIT_SUCCESS) ;
 	}
@@ -97,7 +98,7 @@
 
 	// parse rest of arguments
 	for (int i = 2; i < argc; i++) {
-		if (string (argv[i]) == "-d" || string (argv[i]) == "--distribution") {
+		if (std::string (argv[i]) == "-d" || std::string (argv[i]) == "--distribution") {
 			unsigned int tmp = 0 ;
 
 			if (command.getValue() != EMBED) {
@@ -112,7 +113,7 @@
 				throw SteghideError (_("the argument \"%s\" is incomplete. type \"%s --help\" for help."), argv[i - 1], PROGNAME) ;
 			}
 
-			if (string (argv[i]) == "cnsti") {
+			if (std::string (argv[i]) == "cnsti") {
 				dmtd.setValue (DMTD_CNSTI) ;
 				
 				if ((i + 1 < argc) && (argv[i + 1][0] != '-')) {
@@ -127,7 +128,7 @@
 					dmtdinfo.setValue (di) ;	
 				}
 			}
-			else if (string (argv[i]) == "prndi") {
+			else if (std::string (argv[i]) == "prndi") {
 				dmtd.setValue (DMTD_PRNDI) ;
 				
 				if ((i + 1 < argc) && (argv[i + 1][0] != '-')) {
@@ -147,7 +148,7 @@
 			}
 		}
 
-		else if (string (argv[i]) == "-e" || string (argv[i]) == "--encryption") {
+		else if (std::string (argv[i]) == "-e" || std::string (argv[i]) == "--encryption") {
 			if (command.getValue() != EMBED) {
 				throw SteghideError (_("the argument \"%s\" can only be used with the \"embed\" command. type \"%s --help\" for help."), argv[i], PROGNAME) ;
 			}
@@ -159,7 +160,7 @@
 			encryption.setValue (true) ;
 		}
 
-		else if (string (argv[i]) == "-E" || string (argv[i]) == "--noencryption") {
+		else if (std::string (argv[i]) == "-E" || std::string (argv[i]) == "--noencryption") {
 			if (command.getValue () != EMBED) {
 				throw SteghideError (_("argument \"%s\" can only be used with the \"embed\" command. type \"%s --help\" for help."), argv[i], PROGNAME) ;
 			}
@@ -171,7 +172,7 @@
 			encryption.setValue (false) ;
 		}
 
-		else if (string (argv[i]) == "-h" || string (argv[i]) == "--sthdrencryption") {
+		else if (std::string (argv[i]) == "-h" || std::string (argv[i]) == "--sthdrencryption") {
 			if (sthdrencryption.is_set()) {
 				throw SteghideError (_("the stego header encryption argument can be used only once. type \"%s --help\" for help."), PROGNAME) ;
 			}
@@ -179,7 +180,7 @@
 			sthdrencryption.setValue (true) ;
 		}
 
-		else if (string (argv[i]) == "-H" || string (argv[i]) == "--nosthdrencryption") {
+		else if (std::string (argv[i]) == "-H" || std::string (argv[i]) == "--nosthdrencryption") {
 			if (sthdrencryption.is_set()) {
 				throw SteghideError (_("the stego header encryption argument can be used only once. type \"%s --help\" for help."), PROGNAME) ;
 			}
@@ -187,7 +188,7 @@
 			sthdrencryption.setValue (false) ;
 		}
 
-		else if (string (argv[i]) == "-k" || string (argv[i]) == "--checksum") {
+		else if (std::string (argv[i]) == "-k" || std::string (argv[i]) == "--checksum") {
 			if (command.getValue() != EMBED) {
 				throw SteghideError (_("argument \"%s\" can only be used with the \"embed\" command. type \"%s --help\" for help."), argv[i], PROGNAME) ;
 			}
@@ -199,7 +200,7 @@
 			checksum.setValue (true) ;
 		}
 
-		else if (string (argv[i]) == "-K" || string (argv[i]) == "--nochecksum") {
+		else if (std::string (argv[i]) == "-K" || std::string (argv[i]) == "--nochecksum") {
 			if (command.getValue() != EMBED) {
 				throw SteghideError (_("argument \"%s\" can only be used with the \"embed\" command. type \"%s --help\" for help."), argv[i], PROGNAME) ;
 			}
@@ -211,7 +212,7 @@
 			checksum.setValue (false) ;
 		}
 
-		else if (string (argv[i]) == "-n" || string (argv[i]) == "--embedplainname") {
+		else if (std::string (argv[i]) == "-n" || std::string (argv[i]) == "--embedplainname") {
 			if (command.getValue() != EMBED) {
 				throw SteghideError (_("argument \"%s\" can only be used with the \"embed\" command. type \"%s --help\" for help."), argv[i], PROGNAME) ;
 			}
@@ -223,7 +224,7 @@
 			embedplnfn.setValue (true) ;
 		}
 
-		else if (string (argv[i]) == "-N" || string (argv[i]) == "--notembedplainname") {
+		else if (std::string (argv[i]) == "-N" || std::string (argv[i]) == "--notembedplainname") {
 			if (command.getValue() != EMBED) {
 				throw SteghideError (_("argument \"%s\" can only be used with the \"embed\" command. type \"%s --help\" for help."), argv[i], PROGNAME) ;
 			}
@@ -235,7 +236,7 @@
 			embedplnfn.setValue (false) ;
 		}
 
-		else if (string (argv[i]) == "-c" || string (argv[i]) == "--compatibility") {
+		else if (std::string (argv[i]) == "-c" || std::string (argv[i]) == "--compatibility") {
 			if (compatibility.is_set()) {
 				throw SteghideError (_("the compatibility argument can be used only once. type \"%s --help\" for help."), PROGNAME) ;
 			}
@@ -243,7 +244,7 @@
 			compatibility.setValue (true) ;
 		}
 
-		else if (string (argv[i]) == "-p" || string (argv[i]) == "--passphrase") {
+		else if (std::string (argv[i]) == "-p" || std::string (argv[i]) == "--passphrase") {
 			if (passphrase.is_set()) {
 				throw SteghideError (_("the passphrase argument can be used only once. type \"%s --help\" for help."), PROGNAME) ;
 			}
@@ -263,7 +264,7 @@
 			}
 		}
 
-		else if (string (argv[i]) == "-cf" || string (argv[i]) == "--coverfile") {
+		else if (std::string (argv[i]) == "-cf" || std::string (argv[i]) == "--coverfile") {
 			if (command.getValue() != EMBED) {
 				throw SteghideError (_("argument \"%s\" can only be used with the \"embed\" command. type \"%s --help\" for help."), argv[i], PROGNAME) ;
 			}
@@ -276,7 +277,7 @@
 				throw SteghideError (_("the \"%s\" argument must be followed by the cover file name. type \"%s --help\" for help."), argv[i - 1], PROGNAME) ;
 			}
 
-			if (string (argv[i]) == "-") {
+			if (std::string (argv[i]) == "-") {
 				cvrfn.setValue ("") ;
 			}
 			else {
@@ -284,7 +285,7 @@
 			}
 		}
 
-		else if (string (argv[i]) == "-sf" || string (argv[i]) == "--stegofile") {
+		else if (std::string (argv[i]) == "-sf" || std::string (argv[i]) == "--stegofile") {
 			if (stgfn.is_set()) {
 				throw SteghideError (_("the stego file name argument can be used only once. type \"%s --help\" for help."), PROGNAME) ;
 			}
@@ -293,7 +294,7 @@
 				throw SteghideError (_("the \"%s\" argument must be followed by the stego file name. type \"%s --help\" for help."), argv[i - 1], PROGNAME) ;
 			}
 
-			if (string (argv[i]) == "-") {
+			if (std::string (argv[i]) == "-") {
 				stgfn.setValue ("") ;
 			}
 			else {
@@ -301,7 +302,7 @@
 			}
 		}
 
-		else if (string (argv[i]) == "-pf" || string (argv[i]) == "--plainfile") {
+		else if (std::string (argv[i]) == "-pf" || std::string (argv[i]) == "--plainfile") {
 			if (plnfn.is_set()) {
 				throw SteghideError (_("the plain file name argument can be used only once. type \"%s --help\" for help."), PROGNAME) ;
 			}
@@ -310,7 +311,7 @@
 				throw SteghideError (_("the \"%s\" argument must be followed by the plain file name. type \"%s --help\" for help."), argv[i - 1], PROGNAME) ;
 			}
 
-			if (string (argv[i]) == "-") {
+			if (std::string (argv[i]) == "-") {
 				plnfn.setValue ("") ;
 			}
 			else {
@@ -318,7 +319,7 @@
 			}
 		}
 
-		else if (string (argv[i]) == "-f" || string (argv[i]) == "--force") {
+		else if (std::string (argv[i]) == "-f" || std::string (argv[i]) == "--force") {
 			if (force.is_set()) {
 				throw SteghideError (_("the force argument can be used only once. type \"%s --help\" for help."), PROGNAME) ;
 			}
@@ -326,7 +327,7 @@
 			force.setValue (true);
 		}
 
-		else if (string (argv[i]) == "-q" || string (argv[i]) == "--quiet") {
+		else if (std::string (argv[i]) == "-q" || std::string (argv[i]) == "--quiet") {
 			if (verbosity.is_set()) {
 				throw SteghideError (_("the \"%s\" argument cannot be used here because the verbosity has already been set."), argv[i]) ;
 			}
@@ -334,7 +335,7 @@
 			verbosity.setValue (QUIET) ;
 		}
 
-		else if (string (argv[i]) == "-v" || string (argv[i]) == "--verbose") {
+		else if (std::string (argv[i]) == "-v" || std::string (argv[i]) == "--verbose") {
 			if (verbosity.is_set()) {
 				throw SteghideError (_("the \"%s\" argument cannot be used here because the verbosity has already been set."), argv[i]) ;
 			}
