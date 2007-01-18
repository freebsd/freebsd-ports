Gfortran uses only one underscore(?)

--- src/include/cdflib.h~	Wed Oct  4 05:13:39 2006
+++ src/include/cdflib.h	Wed Jan 17 15:46:50 2007
@@ -356,7 +356,7 @@
     defined(__MINGW32__)
 #  if (defined(linux) && !defined(__ICC)) || defined(__CYGWIN__) || \
       defined(macosX) || \
-      defined(sun) || defined(__MINGW32__) || defined(__FreeBSD__)
+      defined(sun) || defined(__MINGW32__)
 #    define Fif_ENTRYPOINT(ep__,ep_,ep,EP) ep__
 #  else
 #    define Fif_ENTRYPOINT(ep__,ep_,ep,EP) ep_
