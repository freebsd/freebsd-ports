--- print.cc.orig	1993-08-02 05:28:21.000000000 +0900
+++ print.cc	2014-01-22 10:39:29.000000000 +0900
@@ -11,7 +11,8 @@
 //  to the comments or the code of this program, but if reported
 //  to me then an attempt will be made to fix them.
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -33,7 +34,7 @@
 {
   char *ptr ;            // Pointer to current time or date string.
   int len ;
-  long clock ;           // Used by the localtime function call.
+  time_t clock ;           // Used by the localtime function call.
   struct stat status ;   // Stat(2) information from current file (-modtime).
   struct tm *tm ;        // Used by the localtime and asctime calls.
   char *timenow ;        // Used to set TimeNow field with users name.
@@ -68,7 +69,7 @@
 
 
 void
-Print::end(enum action_type op)
+Print::end(action_type op)
 {
   int pval ;
 
@@ -316,7 +317,7 @@
 
 
 void
-Print::show_text(enum text_type op, char *hdr, char *str)
+Print::show_text(text_type op, char *hdr, char *str)
 {
   static char *fontstr[MAXTTYPES] = {
                  "BoldFont ",              // T_BOLD.
@@ -355,7 +356,7 @@
 
 
 void
-Print::start(enum action_type op)
+Print::start(action_type op)
 {
   switch (op)
     {
