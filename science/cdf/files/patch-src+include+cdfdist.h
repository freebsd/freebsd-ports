--- src/include/cdflib.h.orig	2008-05-02 20:16:55.000000000 +0200
+++ src/include/cdflib.h	2008-08-19 21:59:08.000000000 +0200
@@ -370,7 +370,7 @@
     defined(__MINGW32__)
 #  if (defined(linux) && !defined(__ICC)) || defined(__CYGWIN__) || \
       defined(macosXppc) || defined(macosXintel) || \
-      defined(sun) || defined(__MINGW32__) || defined(__FreeBSD__)
+      defined(sun) || defined(__MINGW32__)
 #    define Fif_ENTRYPOINT(ep__,ep_,ep,EP) ep__
 #  else
 #    define Fif_ENTRYPOINT(ep__,ep_,ep,EP) ep_
