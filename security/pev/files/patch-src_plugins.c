--- src/plugins.c.orig	2017-01-06 22:27:18 UTC
+++ src/plugins.c
@@ -167,7 +167,7 @@ int plugins_load_all_from_directory(cons
 				const char *filename = dir_entry->d_name;
 
 				// TODO(jweyrich): Use macro conditions for each system: .so, .dylib, .dll
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 				const bool possible_plugin = utils_str_ends_with(filename, ".so") != 0;
 #elif defined(__APPLE__)
 				const bool possible_plugin = utils_str_ends_with(filename, ".dylib") != 0;
