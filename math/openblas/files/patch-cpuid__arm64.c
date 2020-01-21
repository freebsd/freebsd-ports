--- cpuid_arm64.c.orig	2019-04-29 17:22:19 UTC
+++ cpuid_arm64.c
@@ -180,6 +180,8 @@ int detect(void)
 
 
 	}
+#else
+	return CPU_ARMV8;
 #endif
 
 	return CPU_UNKNOWN;
