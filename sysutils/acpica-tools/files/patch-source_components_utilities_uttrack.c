--- source/components/utilities/uttrack.c.orig	2019-08-16 15:01:14 UTC
+++ source/components/utilities/uttrack.c
@@ -864,7 +864,7 @@ AcpiUtDumpAllocations (
 
                     case ACPI_DESC_TYPE_PARSER:
 
-                        AcpiOsPrintf ("AmlOpcode 0x%04hX\n",
+                        AcpiOsPrintf ("AmlOpcode 0x%04X\n",
                             Descriptor->Op.Asl.AmlOpcode);
                         break;
 
