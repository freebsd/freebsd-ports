--- src/fdevent.h.orig	2015-07-26 10:36:36 UTC
+++ src/fdevent.h
@@ -46,7 +46,7 @@
 # include <port.h>
 #endif
 
-#if defined HAVE_SYS_EVENT_H && defined HAVE_KQUEUE
+#if defined HAVE_SYS_EVENT_H && defined HAVE_KQUEUE && !defined HAVE_LIBEV
 # define USE_FREEBSD_KQUEUE
 #endif
 
