--- ./graphics.c.orig	1990-02-02 03:02:42.000000000 +0100
+++ ./graphics.c	2012-08-24 12:51:05.209915967 +0200
@@ -20,7 +20,9 @@
 #include "color.h"
 #include "extern.h"
 
+void make_registers();
 
+void
 but_text(row, column, portion, state)
 int row, column, portion ;
 enum but_state state ;
@@ -116,6 +118,7 @@
 }
 
 
+void
 grey_buttons(base)     /* Grey out numeric buttons depending upon base. */
 enum base_type base ;
 {
@@ -142,6 +145,7 @@
 }
 
 
+void
 handle_down_event(type)
 int type ;
 {
@@ -263,6 +267,7 @@
 }
 
 
+void
 make_registers()           /* Calculate memory register frame values. */
 {
   char line[MAXLINE] ;     /* Current memory register line. */
@@ -279,6 +284,7 @@
 }
 
 
+void
 process_event(type)       /* Process this event. */
 int type ;
 {
