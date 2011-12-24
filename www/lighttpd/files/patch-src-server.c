--- src/server.c.orig	2011-12-24 01:18:53.093922971 +0100
+++ src/server.c	2011-12-24 01:18:56.738921103 +0100
@@ -411,7 +411,7 @@
       "\nNetwork handler:\n\n"
 #if defined(USE_LINUX_SENDFILE) || defined(USE_FREEBSD_SENDFILE) || defined(USE_SOLARIS_SENDFILEV) || defined(USE_AIX_SENDFILE)
       "\t+ sendfile\n"
-#else
+#endif
   #ifdef USE_WRITEV
       "\t+ writev\n"
   #else
@@ -422,7 +422,6 @@
   #else
       "\t- mmap support\n"
   #endif
-#endif
       "\nFeatures:\n\n"
 #ifdef HAVE_IPV6
       "\t+ IPv6 support\n"
