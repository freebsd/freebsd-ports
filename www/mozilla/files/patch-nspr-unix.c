--- nsprpub/pr/src/md/unix/unix.c.orig	Sat May 31 18:06:04 2003
+++ nsprpub/pr/src/md/unix/unix.c	Sat May 31 18:04:43 2003
@@ -65,7 +65,8 @@
  * PRInt32* pointer to a _PRSockLen_t* pointer.
  */
 #if defined(HAVE_SOCKLEN_T) \
-    || (defined(LINUX) && defined(__GLIBC__) && __GLIBC__ >= 2)
+    || (defined(LINUX) && defined(__GLIBC__) && __GLIBC__ >= 2) \
+    || defined(FREEBSD)
 #define _PRSockLen_t socklen_t
 #elif defined(IRIX) || defined(HPUX) || defined(OSF1) || defined(SOLARIS) \
     || defined(AIX4_1) || defined(LINUX) || defined(SONY) \
@@ -73,7 +74,7 @@
     || defined(SUNOS4) || defined(NCR) || defined(DARWIN) \
     || defined(NEXTSTEP) || defined(QNX)
 #define _PRSockLen_t int
-#elif (defined(AIX) && !defined(AIX4_1)) || defined(FREEBSD) \
+#elif (defined(AIX) && !defined(AIX4_1)) \
     || defined(NETBSD) || defined(OPENBSD) || defined(UNIXWARE) \
     || defined(DGUX) || defined(VMS) || defined(NTO)
 #define _PRSockLen_t size_t
