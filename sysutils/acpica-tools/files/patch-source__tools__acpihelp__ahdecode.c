--- ../../source/tools/acpihelp/ahdecode.c.orig	2015-05-15 19:49:26.000000000 -0400
+++ ../../source/tools/acpihelp/ahdecode.c	2015-06-03 16:12:16.361454000 -0400
@@ -912,12 +912,32 @@
     const AH_UUID           *Info;
 
 
-    printf ("ACPI-related UUIDs:\n\n");
+    printf ("ACPI-related UUIDs/GUIDs:\n");
+
+    /* Display entire table of known ACPI-related UUIDs/GUIDs */
 
     for (Info = AcpiUuids; Info->Description; Info++)
     {
-        printf ("%32s : %s\n", Info->Description, Info->String);
+        if (!Info->String) /* Null UUID string means group description */
+        {
+            printf ("\n%36s\n", Info->Description);
+        }
+        else
+        {
+            printf ("%32s : %s\n", Info->Description, Info->String);
+        }
     }
+
+    /* Help info on how UUIDs/GUIDs strings are encoded */
+
+    printf ("\n\nByte encoding of UUID/GUID strings"
+        " into ACPI Buffer objects (use ToUUID from ASL):\n\n");
+
+    printf ("%32s : %s\n", "Input UUID/GUID String format",
+        "aabbccdd-eeff-gghh-iijj-kkllmmnnoopp");
+
+    printf ("%32s : %s\n", "Expected output ACPI buffer",
+        "dd,cc,bb,aa, ff,ee, hh,gg, ii,jj, kk,ll,mm,nn,oo,pp");
 }
 
 
