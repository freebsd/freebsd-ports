--- spunk/syserror.cc.orig	Sat Feb 26 18:04:03 2000
+++ spunk/syserror.cc	Sat Feb 26 18:04:18 2000
@@ -238,7 +238,7 @@
 		return FormatStr (LoadMsg (msUnknown).GetStr (), Code);
 	    } else {
 #ifndef SOLARIS
-		char* Msg = sys_errlist [Code];
+		char* Msg = (char *)sys_errlist [Code];
 #else
 		char* Msg = strerror (Code);
 #endif
