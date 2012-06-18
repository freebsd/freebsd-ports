--- src/samearchive.cpp~	2010-02-04 09:08:04.000000000 +0100
+++ src/samearchive.cpp	2012-06-18 11:33:47.307181515 +0200
@@ -162,7 +162,9 @@
 {
 #if HAVE_MALLOC
 #if __BSD_VISIBLE
+#if __FreeBSD_version < 1000000
 	_malloc_options = "H";
+#endif // __FreeBSD_version
 #endif // __BSD_VISIBLE
 #else // HAVE_MALLOC
 #error malloc function required, see file config.h.in
