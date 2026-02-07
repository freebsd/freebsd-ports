--- cpuid_arm.c.orig	2016-09-01 03:58:42 UTC
+++ cpuid_arm.c
@@ -181,7 +181,12 @@ int detect(void)
 	  }
 
 	}
-
+#else
+#if (__ARM_ARCH == 7)
+	return CPU_ARMV7;
+#else
+	return CPU_ARMV6;
+#endif
 #endif
 
 	return CPU_UNKNOWN;
