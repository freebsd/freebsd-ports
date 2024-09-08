--- source/common/dmtbdump3.c.orig	2024-08-27 21:14:55 UTC
+++ source/common/dmtbdump3.c
@@ -178,7 +178,7 @@ AcpiDmDumpSlic (
 {
 
     (void) AcpiDmDumpTable (Table->Length, sizeof (ACPI_TABLE_HEADER),
-        (void *) (Table + sizeof (*Table)),
+        (void *) ((UINT8 *)Table + sizeof (*Table)),
         Table->Length - sizeof (*Table), AcpiDmTableInfoSlic);
 }
 
