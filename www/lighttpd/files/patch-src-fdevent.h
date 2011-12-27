--- src/fdevent.h.orig	2011-12-19 07:41:33.183877666 +0100
+++ src/fdevent.h	2011-12-19 07:42:01.457863868 +0100
@@ -54,7 +54,7 @@
 # include <port.h>
 #endif
 
-#if defined HAVE_SYS_EVENT_H && defined HAVE_KQUEUE
+#if defined HAVE_SYS_EVENT_H && defined HAVE_KQUEUE && !defined HAVE_LIBEV
 # define USE_FREEBSD_KQUEUE
 # include <sys/event.h>
 #endif
