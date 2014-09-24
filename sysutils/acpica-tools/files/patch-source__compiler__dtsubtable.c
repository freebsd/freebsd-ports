--- ../../source/compiler/dtsubtable.c	2014-08-28 13:10:01.000000000 -0400
+++ ../../source/compiler/dtsubtable.c	2014-09-19 16:47:23.000000000 -0400
@@ -73,13 +73,15 @@
     DT_SUBTABLE             **RetSubtable)
 {
     DT_SUBTABLE             *Subtable;
+    char                    *String;
 
 
     Subtable = UtSubtableCacheCalloc ();
 
     /* Create a new buffer for the subtable data */
 
-    Subtable->Buffer = ACPI_CAST_PTR (UINT8, UtStringCacheCalloc (Length));
+    String = UtStringCacheCalloc (Length);
+    Subtable->Buffer = ACPI_CAST_PTR (UINT8, String);
     ACPI_MEMCPY (Subtable->Buffer, Buffer, Length);
 
     Subtable->Length = Length;
