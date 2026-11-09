--- src/cxx_supportlib/vendor-modified/libev/ev.c.orig	2026-11-02 08:21:03 UTC
+++ src/cxx_supportlib/vendor-modified/libev/ev.c
@@ -3153,7 +3153,7 @@ ev_recommended_backends (void) EV_NOEXCEPT
 {
   unsigned int flags = ev_supported_backends ();
 
-#ifndef __NetBSD__
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
   /* kqueue is borked on everything but netbsd apparently */
   /* it usually doesn't work correctly on anything but sockets and pipes */
   flags &= ~EVBACKEND_KQUEUE;
