--- ./src/include/cdflib.h.orig	Mon Jul 11 23:51:18 2005
+++ ./src/include/cdflib.h	Fri Jan 27 21:51:27 2006
@@ -351,7 +351,7 @@
 #if defined(unix) && !defined(AIX) && !defined(Mach) && !defined(hpux) || \
     defined(__MINGW32__)
 #  if defined(linux) || defined(__CYGWIN__) || defined(macosX) || \
-      defined(sun) || defined(__MINGW32__)
+      defined(sun) || defined(__MINGW32__) || defined(__FreeBSD__)
 #    define Fif_ENTRYPOINT(ep__,ep_,ep,EP) ep__
 #  else
 #    define Fif_ENTRYPOINT(ep__,ep_,ep,EP) ep_
