--- src/main.cc.orig	Sat Dec 18 04:59:03 2004
+++ src/main.cc	Sat Feb  5 03:27:07 2005
@@ -42,6 +42,27 @@
 #endif /* USE_TEXT_BLOB */
 
 
+// XXX Implement strndup for FreeBSD.
+#ifdef __FreeBSD__
+#ifdef __cplusplus
+extern "C" {
+#endif
+static char *
+mystrndup(const char *str, int len) {
+    char *ret;
+
+    if ((str == NULL || len < 0)) return(NULL);
+    ret = (char *)malloc(len + 1);
+    if (ret == NULL) return(NULL);
+    memcpy(ret, str, len);
+    ret[len] = '\0';
+    return(ret);
+}
+#ifdef __cplusplus
+}
+#endif
+#endif
+
 int filter_good_uid = 0,
 	filter_good_pid = 0;
 bool allow_autosize = true;
@@ -153,7 +174,11 @@
 		if (arg == NULL) {
 			die (N_("--geometry option requires argument giving X-style geometry specification.\n"));
 		};
+#ifdef __FreeBSD__
+		lava_default_geometry = mystrndup(arg, 1024); // leaks memory, but probably doesn't matter
+#else
 		lava_default_geometry = strndup(arg, 1024); // leaks memory, but probably doesn't matter
+#endif
 		break;
 	case OPTION_DEBUG:
 		lava_debug = true;
