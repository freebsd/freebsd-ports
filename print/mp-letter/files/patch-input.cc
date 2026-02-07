--- input.cc.orig	1993-08-02 05:28:22.000000000 +0900
+++ input.cc	2014-01-22 10:40:22.000000000 +0900
@@ -11,7 +11,8 @@
 //  to the comments or the code of this program, but if reported
 //  to me then an attempt will be made to fix them.
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -134,6 +135,8 @@
 
       else if (!argcmp(argv[i], "-from", 4))     // Print originators name.
         print_orig = 1 ;
+      else if (!argcmp(argv[i], "-F", 2))     	// backward compatiblity
+        print_orig = 1 ;
 
       else if (!argcmp(argv[i], "-help", 2))     // Print usage message.
         usage() ;
@@ -273,11 +276,11 @@
       case DO_TEXT : prt.message_for = "Listing for ";
                      digest = 0 ;
                      break ;
-      case DO_MAIL : prt.message_for = digest ? "Mail digest for "
-                                              : "Mail for " ;
+      case DO_MAIL : prt.message_for = digest ? (char *) "Mail digest for "
+                                              : (char *) "Mail for " ;
                      break ;
-      case DO_NEWS : prt.message_for = digest ? "News digest for "
-                                              : "News for " ;
+      case DO_NEWS : prt.message_for = digest ? (char *) "News digest for "
+                                              : (char *) "News for " ;
                      break ;
     }
 }
