--- common/uproc.c.orig	Fri Oct 25 11:34:37 2002
+++ common/uproc.c	Fri Oct 25 11:35:08 2002
@@ -35,7 +35,7 @@
 static void
 ReapChild()
 {
-#if defined(WNOHANG) && !defined(SYSV) && !defined(SVR4)
+#if defined(WNOHANG) && !defined(SYSV) && !defined(SVR4) && !defined(__FreeBSD__)
   int pid;
 #endif
   extern int errno;
@@ -45,7 +45,7 @@
   * It would probably be better to use the POSIX mechanism here,but I have not
   * checked into it.  This gets us off the ground with SYSV.  RSE@GMI
   */
-#if defined(WNOHANG) && !defined(SYSV) && !defined(SVR4) && !defined(__QNX__) && !defined(__EMX__)
+#if defined(WNOHANG) && !defined(SYSV) && !defined(SVR4) && !defined(__QNX__) && !defined(__EMX__) && !defined(__FreeBSD__)
   union wait st;
 
   do 
