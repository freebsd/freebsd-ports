--- src/utils/os_config_init.c.orig	2026-01-10 11:13:13 UTC
+++ src/utils/os_config_init.c
@@ -335,7 +335,7 @@ static Bool get_default_install_path(char *file_path, 
 #else
 
 //dlinfo
-#if defined(__DARWIN__) || defined(__APPLE__)
+#if defined(__DARWIN__) || defined(__APPLE__) || defined(__FreeBSD__)
 #include <dlfcn.h>
 
 typedef Dl_info _Dl_info;
@@ -357,7 +357,7 @@ static Bool get_default_install_path(char *file_path, 
 {
 	char app_path[GF_MAX_PATH];
 	char *sep;
-#if (defined(__DARWIN__) || defined(__APPLE__) || defined(GPAC_CONFIG_LINUX))
+#if (defined(__DARWIN__) || defined(__APPLE__) || defined(GPAC_CONFIG_LINUX) || defined(__FreeBSD__))
 	u32 size;
 #endif
 
@@ -419,7 +419,7 @@ static Bool get_default_install_path(char *file_path, 
 			return 1;
 		}
 
-#elif defined(GPAC_CONFIG_LINUX)
+#elif defined(GPAC_CONFIG_LINUX) || defined(__FreeBSD__)
 		size = readlink("/proc/self/exe", file_path, GF_MAX_PATH-1);
 		if (size>0) {
 			file_path[size] = 0;
@@ -456,7 +456,7 @@ static Bool get_default_install_path(char *file_path, 
 	}
 
 	if (path_type==GF_PATH_LIB) {
-#if defined(__DARWIN__) || defined(__APPLE__) || defined(GPAC_CONFIG_LINUX)
+#if defined(__DARWIN__) || defined(__APPLE__) || defined(GPAC_CONFIG_LINUX) || defined(__FreeBSD__)
 		_Dl_info dl_info;
 		dl_info.dli_fname = NULL;
 		if (dladdr((void *)get_default_install_path, &dl_info)
