--- source/common/dmtables.c.orig	2019-08-16 15:01:10 UTC
+++ source/common/dmtables.c
@@ -327,7 +327,7 @@ AdCreateTableHeader (
      * makes it easier to rename the disassembled ASL file if needed.
      */
     AcpiOsPrintf (
-        "DefinitionBlock (\"\", \"%4.4s\", %hu, \"%.6s\", \"%.8s\", 0x%8.8X)\n",
+        "DefinitionBlock (\"\", \"%4.4s\", %u, \"%.6s\", \"%.8s\", 0x%8.8X)\n",
         Table->Signature, Table->Revision,
         Table->OemId, Table->OemTableId, Table->OemRevision);
 }
