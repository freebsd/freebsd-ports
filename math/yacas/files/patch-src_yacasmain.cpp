--- src/yacasmain.cpp.orig	2014-12-11 21:11:48.000000000 +0000
+++ src/yacasmain.cpp	2014-12-11 21:13:21.000000000 +0000
@@ -1083,7 +1083,9 @@
     unsigned char first_stack_var = 0;
     the_first_stack_var = &first_stack_var;
 
-#if defined (__APPLE__)
+#if defined (__FreeBSD__)
+	root_dir = "%%DATADIR%%/scripts";
+#elif defined (__APPLE__)
     char buf[PATH_MAX];
     uint32_t size = sizeof (buf);
     _NSGetExecutablePath(buf, &size);
