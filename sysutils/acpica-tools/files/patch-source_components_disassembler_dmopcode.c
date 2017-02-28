--- source/components/disassembler/dmopcode.c.orig	2017-02-25 00:43:55 UTC
+++ source/components/disassembler/dmopcode.c
@@ -443,7 +443,10 @@ AcpiDmFieldPredefinedDescription (
             ACPI_CAST_PTR (char, Info->Description));
     }
 
-    ACPI_FREE (Tag); /* Tag was allocated in AcpiGetTagPathname */
+    /* AML buffer (String) was allocated in AcpiGetTagPathname */
+
+    ACPI_FREE (IndexOp->Common.Value.String);
+
 #endif
     return;
 }
