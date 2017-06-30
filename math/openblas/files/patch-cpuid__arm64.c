--- cpuid_arm64.c.orig	2016-09-01 03:58:42 UTC
+++ cpuid_arm64.c
@@ -132,6 +132,8 @@ int detect(void)
 
 
 	}
+#else
+	return CPU_ARMV8;
 #endif
 
 	return CPU_UNKNOWN;
