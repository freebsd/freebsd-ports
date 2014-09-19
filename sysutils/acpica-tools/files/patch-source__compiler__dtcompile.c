--- ../../source/compiler/dtcompile.c	2014-08-28 13:10:01.000000000 -0400
+++ ../../source/compiler/dtcompile.c	2014-09-19 16:32:31.000000000 -0400
@@ -438,6 +438,7 @@
     UINT8                   *Buffer;
     UINT8                   *FlagBuffer = NULL;
     UINT32                  CurrentFlagByteOffset = 0;
+    char                    *String;
     ACPI_STATUS             Status;
 
 
@@ -465,7 +466,8 @@
 
     if (Length > 0)
     {
-        Subtable->Buffer = ACPI_CAST_PTR (UINT8, UtStringCacheCalloc (Length));
+        String = UtStringCacheCalloc (Length);
+        Subtable->Buffer = ACPI_CAST_PTR (UINT8, String);
     }
     Subtable->Length = Length;
     Subtable->TotalLength = Length;
