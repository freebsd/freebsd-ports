--- src/emacs.c.orig	Wed Sep  4 20:33:38 2002
+++ src/emacs.c	Wed Sep  4 20:33:40 2002
@@ -510,8 +510,6 @@
 {
   char stack_bottom_variable;
   int skip_args = 0;
-  extern int errno;
-  extern sys_nerr;
 
 #ifdef LINUX_SBRK_BUG
   __sbrk (1);
