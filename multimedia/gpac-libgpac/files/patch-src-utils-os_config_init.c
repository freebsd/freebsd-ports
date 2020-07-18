--- src/utils/os_config_init.c.orig	2020-06-16 16:17:17 UTC
+++ src/utils/os_config_init.c
@@ -58,6 +58,9 @@
 #else
 #ifdef GPAC_CONFIG_LINUX
 #include <unistd.h>
+#elif defined GPAC_CONFIG_FREEBSD
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #endif
 #ifdef GPAC_CONFIG_ANDROID
 #define DEFAULT_ANDROID_PATH_APP	"/data/data/com.gpac.Osmo4"
@@ -294,6 +297,8 @@ static Bool get_default_install_path(char *file_path, 
 	char *sep;
 #if (defined(__DARWIN__) || defined(__APPLE__) || defined(GPAC_CONFIG_LINUX))
 	u32 size;
+#elif defined(GPAC_CONFIG_FREEBSD)
+	size_t size = GF_MAX_PATH;
 #endif
 
 	/*on OSX, Linux & co, user home is where we store the cfg file*/
@@ -369,6 +374,14 @@ static Bool get_default_install_path(char *file_path, 
 			if (sep) {
 				strcpy(file_path, sep);
 			}
+			return 1;
+		}
+#elif defined(GPAC_CONFIG_FREEBSD)
+		int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+		sysctl(mib, 4, file_path, &size, NULL, 0);
+		if (size>0) {
+			char *sep = strrchr(file_path, '/');
+			if (sep) sep[0] = 0;
 			return 1;
 		}
 #endif
