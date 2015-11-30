--- source/components/debugger/dbdisply.c.orig	2015-11-24 15:11:26 UTC
+++ source/components/debugger/dbdisply.c
@@ -671,10 +671,12 @@ AcpiDbDisplayObjectType (
     ACPI_HANDLE             Handle;
     ACPI_DEVICE_INFO        *Info;
     ACPI_STATUS             Status;
+    unsigned long           Address;
     UINT32                  i;
 
 
-    Handle = ACPI_TO_POINTER (strtoul (ObjectArg, NULL, 16));
+    Address = strtoul (ObjectArg, NULL, 16);
+    Handle = ACPI_TO_POINTER (Address);
 
     Status = AcpiGetObjectInfo (Handle, &Info);
     if (ACPI_FAILURE (Status))
