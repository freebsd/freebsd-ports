--- source/common/dmextern.c.orig	2016-03-18 16:25:41 UTC
+++ source/common/dmextern.c
@@ -1101,7 +1101,6 @@ AcpiDmEmitExternals (
      */
     while (AcpiGbl_ExternalList)
     {
-        AcpiGbl_ExternalList = AcpiGbl_ExternalList;
         if (!(AcpiGbl_ExternalList->Flags & ACPI_EXT_EXTERNAL_EMITTED))
         {
             AcpiOsPrintf ("    External (%s%s)",
