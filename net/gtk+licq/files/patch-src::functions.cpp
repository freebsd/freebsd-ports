--- src/functions.cpp	2001/04/23 21:07:27	1.97
+++ src/functions.cpp	2001/05/17 08:34:51	1.98
@@ -989,7 +989,11 @@
 {
     unsigned long   *uinptr;
     GtkWidget       *parent=NULL;
-
+    
+    if (widget == NULL) {
+        return(0);
+    }
+    
     for (;;)
     {
         if (GTK_IS_MENU (widget)) {
