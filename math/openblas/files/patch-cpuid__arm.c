--- cpuid_arm.c.orig	2016-09-01 03:58:42 UTC
+++ cpuid_arm.c
@@ -181,7 +181,8 @@ int detect(void)
 	  }
 
 	}
-
+#else
+	return CPU_ARMV6;
 #endif
 
 	return CPU_UNKNOWN;
