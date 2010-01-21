--- src/include/cdflib.h.orig	2010-01-18 15:22:03.000000000 -0600
+++ src/include/cdflib.h	2010-01-18 15:22:32.000000000 -0600
@@ -375,7 +375,7 @@
 #elif defined(unix) && !defined(AIX) && !defined(Mach) && !defined(hpux) || \
     defined(__MINGW32__)
 #  if (defined(linux) && !defined(__ICC)) || defined(__CYGWIN__) || \
-      defined(sun) || defined(__MINGW32__) || defined(__FreeBSD__) || \
+      defined(sun) || defined(__MINGW32__) || \
       defined(__PPC__)
 #    define Fif_ENTRYPOINT(ep__,ep_,ep,EP) ep__
 #  else
