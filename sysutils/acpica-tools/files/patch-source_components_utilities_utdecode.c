--- source/components/utilities/utdecode.c.orig	2019-02-15 17:38:43 UTC
+++ source/components/utilities/utdecode.c
@@ -632,7 +632,7 @@ static const char           *AcpiGbl_GenericNotify[ACP
     /* 0B */ "System Locality Update",
     /* 0C */ "Reserved (was previously Shutdown Request)",  /* Reserved in ACPI 6.0 */
     /* 0D */ "System Resource Affinity Update",
-    /* 0E */ "Heterogeneous Memory Attributes Update"       /* ACPI 6.2 */
+    /* 0E */ "Heterogeneous Memory Attributes Update",      /* ACPI 6.2 */
     /* 0F */ "Error Disconnect Recover"                     /* ACPI 6.3 */
 };
 
