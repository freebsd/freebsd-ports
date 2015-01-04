--- src/yacasmain.cpp.orig	2014-11-25 15:18:46 UTC
+++ src/yacasmain.cpp
@@ -1083,7 +1083,9 @@ int main(int argc, char** argv)
     unsigned char first_stack_var = 0;
     the_first_stack_var = &first_stack_var;
 
-#if defined (__APPLE__)
+#if defined (__FreeBSD__) || defined (__DragonFly__)
+	root_dir = "%%DATADIR%%/scripts";
+#elif defined (__APPLE__)
     char buf[PATH_MAX];
     uint32_t size = sizeof (buf);
     _NSGetExecutablePath(buf, &size);
