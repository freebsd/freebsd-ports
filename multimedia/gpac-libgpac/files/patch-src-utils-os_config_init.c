--- src/utils/os_config_init.c.orig	2012-03-27 13:48:05.000000000 +0400
+++ src/utils/os_config_init.c	2013-10-12 14:29:52.214068862 +0400
@@ -51,6 +51,9 @@
 #else
 #ifdef GPAC_CONFIG_LINUX
 #include <unistd.h>
+#elif defined GPAC_CONFIG_FREEBSD
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #endif
 #define CFG_FILE_NAME	".gpacrc"
 #define TEST_MODULE		"gm_dummy_in.so"
@@ -225,7 +228,11 @@
 {
 	char app_path[GF_MAX_PATH];
 	char *sep;
+#ifdef GPAC_CONFIG_FREEBSD
+	size_t size = GF_MAX_PATH;
+#else
 	u32 size = GF_MAX_PATH;
+#endif
 
 	/*on OSX, Linux & co, user home is where we store the cfg file*/
 	if (path_type==GF_PATH_CFG) {
@@ -252,6 +259,14 @@
 			if (sep) sep[0] = 0;
 			return 1;
 		}
+#elif defined(GPAC_CONFIG_FREEBSD)
+		int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+		sysctl(mib, 4, file_path, &size, NULL, 0);
+		if (size>0) {
+			char *sep = strrchr(file_path, '/');
+			if (sep) sep[0] = 0;
+			return 1;
+		}
 #endif
 		return 0;
 	}
