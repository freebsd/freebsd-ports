--- src/include/cdflib.h.orig	2019-10-16 16:22:18 UTC
+++ src/include/cdflib.h
@@ -401,8 +401,7 @@
 #elif defined(unix) && !defined(AIX) && !defined(Mach) && !defined(hpux) || \
     defined(__MINGW32__)
 #  if (defined(linux) && !defined(__ICC)) || defined(__CYGWIN__) || \
-      defined(sun) || defined(__MINGW32__) || defined(__FreeBSD__) || \
-      defined(__PPC__)
+      defined(sun) || defined(__MINGW32__)
 #    define Fif_ENTRYPOINT(ep__,ep_,ep,EP) ep__
 #  else
 #    define Fif_ENTRYPOINT(ep__,ep_,ep,EP) ep_
