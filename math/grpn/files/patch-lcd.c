--- lcd.c.orig	2002-04-04 05:46:11.000000000 +0200
+++ lcd.c	2013-11-05 16:42:40.000000000 +0100
@@ -20,6 +20,8 @@ Foundation, Inc., 59 Temple Place - Suit
 /* lcd.c   by Paul Wilkins 3/22/97 */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <gtk/gtk.h>
 #include <gdk/gdkkeysyms.h>
 
