--- veusz/helpers/src/qtloops/isnan.h.orig	2013-11-27 18:00:21 UTC
+++ veusz/helpers/src/qtloops/isnan.h
@@ -50,7 +50,7 @@
 # define isFinite(_a) (_finite(_a)) 	/* Win32 definition */
 #elif defined(__sgi)
 # define isFinite(_a) (_isfinite(_a))
-#elif defined(isfinite)
+#elif defined(isfinite) || defined(__FreeBSD__)
 # define isFinite(_a) (isfinite(_a))
 #elif defined(__osf__)
 # define isFinite(_a) (finite(_a) && !isNaN(_a))
