--- src/samefile.cpp~	2010-07-14 13:22:15.000000000 +0200
+++ src/samefile.cpp	2012-06-18 11:28:10.941708203 +0200
@@ -120,7 +120,9 @@
 {
 #if HAVE_MALLOC
 #if __BSD_VISIBLE
+#if __FreeBSD_version < 1000000
 	_malloc_options = "H";
+#endif // __FreeBSD_version
 #endif // __BSD_VISIBLE
 #else // HAVE_MALLOC
 #error malloc function required, see file config.h.in
