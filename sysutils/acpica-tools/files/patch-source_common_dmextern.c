--- source/common/dmextern.c.orig	2022-10-20 21:12:58 UTC
+++ source/common/dmextern.c
@@ -1493,7 +1493,6 @@ AcpiDmMarkExternalConflict (
     ACPI_EXTERNAL_LIST      *ExternalList = AcpiGbl_ExternalList;
     char                    *ExternalPath;
     char                    *InternalPath;
-    char                    *Temp;
     ACPI_STATUS             Status;
 
 
@@ -1526,13 +1525,6 @@ AcpiDmMarkExternalConflict (
 
     while (ExternalList)
     {
-        Temp = ExternalList->InternalPath;
-        if ((*ExternalList->InternalPath == AML_ROOT_PREFIX) &&
-            (ExternalList->InternalPath[1]))
-        {
-            Temp++;
-        }
-
         if (!strcmp (ExternalList->InternalPath, InternalPath))
         {
             ExternalList->Flags |= ACPI_EXT_CONFLICTING_DECLARATION;
