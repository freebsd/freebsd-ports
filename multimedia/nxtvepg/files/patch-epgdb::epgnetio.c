--- epgdb/epgnetio.c.orig	Sun Nov 17 19:14:32 2002
+++ epgdb/epgnetio.c	Sun Jan  5 23:43:08 2003
@@ -65,7 +65,7 @@
 #include "epgdb/epgdbsav.h"
 #include "epgdb/epgnetio.h"
 
-#if defined(linux) || defined(__NetBSD__)
+#if defined(linux) || defined(__NetBSD__) || defined(__FreeBSD__)
 #define HAVE_GETADDRINFO
 #endif
 
