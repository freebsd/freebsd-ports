--- registry.cpp.orig	2005-08-22 18:47:00 UTC
+++ registry.cpp
@@ -246,7 +246,7 @@ DRIVER_ERROR DeviceRegistry::SelectDevic
             device = eDJ3320;
             match = TRUE;
         }
-		char	*cmdStr = strstr ((const char *) DevIDBuffer+2, "CMD:");
+		const char *cmdStr = strstr ((const char *) DevIDBuffer+2, "CMD:");
 		if (!cmdStr)
 		{
 			cmdStr = strstr ((const char *) DevIDBuffer+2, "COMMAND SET:");
