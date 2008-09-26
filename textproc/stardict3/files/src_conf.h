--- src/conf.h.orig	2008-09-26 09:33:59.000000000 +0800
+++ src/conf.h	2008-09-26 09:34:44.000000000 +0800
@@ -115,7 +115,6 @@
 	std::auto_ptr<config_file> cf;
 	cache_t cache;
 
-#ifdef _WIN32
 static void *memrchr(const void *mem, int c, size_t len) {
 	char *res;
 	char *cmem = (char *)mem;
@@ -127,7 +126,6 @@
 		--res;
 	return res == cmem - 1 ? NULL : res;
 }
-#endif
 
 	template <typename T>
 	void set_value(const char *name, const T& val, bool abs = true) {
