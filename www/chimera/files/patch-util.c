--- src/util.c.orig	Fri Oct 25 11:27:19 2002
+++ src/util.c	Fri Oct 25 11:28:18 2002
@@ -132,7 +132,7 @@
 static void
 ReapChild()
 {
-#if defined(WNOHANG) && !defined(SYSV) && !defined(SVR4)
+#if defined(WNOHANG) && !defined(SYSV) && !defined(SVR4) && !defined(__FreeBSD__)
   int pid;
 #endif
   extern int errno;
@@ -142,7 +142,7 @@
   * It would probably be better to use the POSIX mechanism here,but I have not 
   * checked into it.  This gets us off the ground with SYSV.  RSE@GMI
   */
-#if defined(WNOHANG) && !defined(SYSV) && !defined(SVR4)
+#if defined(WNOHANG) && !defined(SYSV) && !defined(SVR4) && !defined(__FreeBSD__)
   union wait st;
 
   do 
