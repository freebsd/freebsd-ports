--- source/components/namespace/nsdump.c.orig	2019-08-16 15:01:13 UTC
+++ source/components/namespace/nsdump.c
@@ -478,7 +478,7 @@ AcpiNsDumpOneObject (
                     AcpiOsPrintf (" =");
                     for (i = 0; (i < ObjDesc->Buffer.Length && i < 12); i++)
                     {
-                        AcpiOsPrintf (" %.2hX", ObjDesc->Buffer.Pointer[i]);
+                        AcpiOsPrintf (" %2.2X", ObjDesc->Buffer.Pointer[i]);
                     }
                 }
                 AcpiOsPrintf ("\n");
@@ -575,7 +575,7 @@ AcpiNsDumpOneObject (
         case ACPI_TYPE_LOCAL_BANK_FIELD:
         case ACPI_TYPE_LOCAL_INDEX_FIELD:
 
-            AcpiOsPrintf (" Off %.3X Len %.2X Acc %.2hd\n",
+            AcpiOsPrintf (" Off %.3X Len %.2X Acc %.2X\n",
                 (ObjDesc->CommonField.BaseByteOffset * 8)
                     + ObjDesc->CommonField.StartFieldBitOffset,
                 ObjDesc->CommonField.BitLength,
