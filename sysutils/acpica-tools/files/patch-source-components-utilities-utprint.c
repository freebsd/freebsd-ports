--- ../../source/components/utilities/utprint.c.orig	2014-06-27 11:36:15.000000000 -0400
+++ ../../source/components/utilities/utprint.c	2014-06-27 17:27:55.000000000 -0400
@@ -298,6 +298,7 @@
     INT32                   Precision,
     UINT8                   Type)
 {
+    char                    *Pos;
     char                    Sign;
     char                    Zero;
     BOOLEAN                 NeedPrefix;
@@ -354,9 +355,8 @@
 
     /* Generate full string in reverse order */
 
-    i = ACPI_PTR_DIFF (
-            AcpiUtPutNumber (ReversedString, Number, Base, Upper),
-	    ReversedString);
+    Pos = AcpiUtPutNumber (ReversedString, Number, Base, Upper);
+    i = ACPI_PTR_DIFF (Pos, ReversedString);
 
     /* Printing 100 using %2d gives "100", not "00" */
 
