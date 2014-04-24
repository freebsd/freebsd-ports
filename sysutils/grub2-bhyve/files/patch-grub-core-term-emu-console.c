--- grub-core/term/emu/console.c.bak	2014-04-17 20:03:51.000000000 +0400
+++ grub-core/term/emu/console.c	2014-04-17 20:03:13.000000000 +0400
@@ -42,6 +42,12 @@
 #error What the hell?
 #endif
 
+#ifdef BHYVE	/* should include <sys/param.h> */
+#ifndef MIN
+#define MIN(a,b) (((a)<(b))?(a):(b))
+#endif
+#endif
+
 static int grub_console_attr = A_NORMAL;
 
 grub_uint8_t grub_console_cur_color = 7;
@@ -176,6 +182,11 @@
 
   getyx (stdscr, y, x);
 
+#ifdef BHYVE
+  x = MIN(x, 255);
+  y = MIN(y, 255);
+#endif
+
   return (x << 8) | y;
 }
 
@@ -187,6 +198,11 @@
 
   getmaxyx (stdscr, y, x);
 
+#ifdef BHYVE
+  x = MIN(x, 255);
+  y = MIN(y, 255);
+#endif
+
   return (x << 8) | y;
 }
 
