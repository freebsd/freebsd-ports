--- src/properties.c.ori	2012-03-15 13:29:24.000000000 +0100
+++ src/properties.c	2012-03-15 13:30:09.000000000 +0100
@@ -448,7 +448,7 @@
         WMReleasePropList(mpProp);
     }
 
-    if (WMWritePropListToFile(props, getFileName(), FALSE) == FALSE)
+    if (WMWritePropListToFile(props, getFileName()) == FALSE)
         printf("Error occurred synchronizing proplist\n");
 
     WMReleasePropList(props);
