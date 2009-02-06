--- common-src/event.c.orig	2009-02-04 07:50:43.000000000 +0900
+++ common-src/event.c	2009-02-04 07:50:20.000000000 +0900
@@ -480,7 +480,7 @@
  * some tricky race conditions and extra machinery.  Since there are few, if any,
  * users of a glib version this old, such machinery wouldn't get much testing.
  */
-#if (GLIB_MAJOR_VERSION < 2 || (GLIB_MAJOR_VERSION == 2 && GLIB_MINOR_VERSION < 6))
+#if (1 || GLIB_MAJOR_VERSION < 2 || (GLIB_MAJOR_VERSION == 2 && GLIB_MINOR_VERSION < 6))
 typedef struct ChildWatchSource {
     GSource source; /* must be the first element in the struct */
 
