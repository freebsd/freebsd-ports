--- ./lib/tty/tty-ncurses.c.orig	2013-11-29 19:27:07.000000000 +0100
+++ ./lib/tty/tty-ncurses.c	2013-12-07 10:50:19.000000000 +0100
@@ -49,6 +49,7 @@
 #include "tty-internal.h"       /* mc_tty_normalize_from_utf8() */
 #include "tty.h"
 #include "color-internal.h"
+#include "key.h"
 #include "mouse.h"
 #include "win.h"
 
@@ -530,6 +531,7 @@
     if (mc_global.utf8_display || c > 255)
     {
         int res;
+        unsigned char str[UTF8_CHAR_LEN + 1];
 
         res = g_unichar_to_utf8 (c, (char *) str);
         if (res == 0)
@@ -540,7 +542,6 @@
         }
         else
         {
-            unsigned char str[UTF8_CHAR_LEN + 1];
             const char *s;
 
             str[res] = '\0';
