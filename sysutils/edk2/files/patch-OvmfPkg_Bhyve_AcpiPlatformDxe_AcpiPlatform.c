--- OvmfPkg/Bhyve/AcpiPlatformDxe/AcpiPlatform.c.orig	2023-09-07 08:35:06 UTC
+++ OvmfPkg/Bhyve/AcpiPlatformDxe/AcpiPlatform.c
@@ -259,19 +259,17 @@ InstallAcpiTables (
              BHYVE_BIOS_PHYSICAL_END,
              &Rsdp
              );
-  if (EFI_ERROR (Status)) {
-    return Status;
-  }
-
-  Status = InstallAcpiTablesFromRsdp (
-             AcpiTable,
-             Rsdp
-             );
   if (!EFI_ERROR (Status)) {
-    return EFI_SUCCESS;
+    Status = InstallAcpiTablesFromRsdp (
+              AcpiTable,
+              Rsdp
+              );
+    if (!EFI_ERROR (Status)) {
+      return EFI_SUCCESS;
+    }
   }
 
-  if (Status != EFI_NOT_FOUND) {
+  if (EFI_ERROR (Status)) {
     DEBUG (
       (
        DEBUG_WARN,
@@ -280,7 +278,6 @@ InstallAcpiTables (
        Status
       )
       );
-    return Status;
   }
 
   Status = InstallOvmfFvTables (AcpiTable);
