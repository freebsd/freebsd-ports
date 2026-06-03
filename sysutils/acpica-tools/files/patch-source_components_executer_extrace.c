--- source/components/executer/extrace.c.orig	2025-08-07 21:27:10 UTC
+++ source/components/executer/extrace.c
@@ -301,7 +301,7 @@ AcpiExTraceArgs(ACPI_OPERAND_OBJECT **Params, UINT32 C
         switch (obj_desc->Common.Type)
         {
         case ACPI_TYPE_INTEGER:
-            ACPI_DEBUG_PRINT_RAW((ACPI_DB_TRACE_POINT, "%lx", obj_desc->Integer.Value));
+            ACPI_DEBUG_PRINT_RAW((ACPI_DB_TRACE_POINT, "%jx", (uintmax_t)obj_desc->Integer.Value));
             break;
 
         case ACPI_TYPE_STRING:
