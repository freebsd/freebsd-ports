--- dao/dao.cc.orig	Thu Feb 12 02:13:31 2004
+++ dao/dao.cc	Tue Mar  2 17:22:11 2004
@@ -703,7 +703,7 @@
 
     setsid(); // detach from controlling terminal
 
-#ifdef HAVE_MLOCKALL
+#if defined(HAVE_MLOCKALL) && !defined(__FreeBSD__)
     if (geteuid() == 0) {
       if (mlockall(MCL_CURRENT|MCL_FUTURE) != 0) {
 	message(-1, "Cannot lock memory pages: %s", strerror(errno));
@@ -737,7 +737,7 @@
     break;
   }
 
-#ifdef HAVE_MLOCKALL
+#if defined(HAVE_MLOCKALL) && !defined(__FreeBSD__)
   if (geteuid() == 0) {
     if (mlockall(MCL_CURRENT|MCL_FUTURE) != 0) {
       message(-1, "Cannot lock memory pages: %s", strerror(errno));
@@ -762,7 +762,7 @@
     cdr->abortDao(); // abort writing process
 
  fail:
-#ifdef HAVE_MUNLOCKALL
+#if defined(HAVE_MUNLOCKALL) && !defined(__FreeBSD__)
   munlockall();
 #endif
 
