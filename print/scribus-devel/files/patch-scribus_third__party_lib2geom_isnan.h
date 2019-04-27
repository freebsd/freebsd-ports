--- scribus/third_party/lib2geom/isnan.h.orig	2018-12-25 11:40:59 UTC
+++ scribus/third_party/lib2geom/isnan.h
@@ -33,7 +33,7 @@
 # define is_nan(_a) (__isnan(_a))	/* MacOSX/Darwin definition < 10.4 */
 #elif defined(WIN32) || defined(_isnan)
 # define is_nan(_a) (_isnan(_a)) 	/* Win32 definition */
-#elif defined(isnan) || defined(__FreeBSD__)
+#elif defined(isnan)
 # define is_nan(_a) (isnan(_a))		/* GNU definition */
 #else
 # define is_nan(_a) (std::isnan(_a))
