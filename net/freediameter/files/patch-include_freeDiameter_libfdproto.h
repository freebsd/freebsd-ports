--- include/freeDiameter/libfdproto.h.orig	2020-10-10 04:58:27 UTC
+++ include/freeDiameter/libfdproto.h
@@ -292,8 +292,13 @@ extern int fd_g_debug_lvl;
 
 /* A version of __FILE__ without the full path. This is specific to each C file being compiled */
 static char * file_bname = NULL;
-static char * file_bname_init(char * full) { file_bname = basename(full); return file_bname; }
-#define __STRIPPED_FILE__	(file_bname ?: file_bname_init((char *)__FILE__))
+static char * file_bname_init(const char * full) {
+	/* Since FreeBSD 12.0, basename() modifies the provided
+	 * input buffer, so we must strdup() the input string,
+	 * otherwise we'd segfault on __FILE__ which is const. */
+	file_bname = basename(strdup(full));
+	return file_bname; }
+#define __STRIPPED_FILE__	(file_bname ?: file_bname_init(__FILE__))
 
 
 
