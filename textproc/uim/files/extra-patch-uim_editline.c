--- uim/editline.c.orig	Wed Dec  7 21:39:32 2005
+++ uim/editline.c	Tue Jan 31 01:48:45 2006
@@ -52,6 +52,10 @@
 
 #include "editline.h"
 
+#ifndef H_SETSIZE
+#define H_SETSIZE	1
+#endif
+
 static EditLine *el;
 static History *hist;
 static HistEvent hev;
@@ -65,7 +69,7 @@
 void
 editline_init(void)
 {
-  el = el_init("uim", stdin, stdout, stderr);
+  el = el_init("uim", stdin, stdout);
   el_set(el, EL_PROMPT, &prompt);
   el_set(el, EL_EDITOR, "emacs");
 
