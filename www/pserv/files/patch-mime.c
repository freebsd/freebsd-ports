--- sources/mime.c.orig	Thu Sep 18 15:26:55 2003
+++ sources/mime.c	Wed Oct 15 18:38:42 2003
@@ -43,8 +43,8 @@
     f = fopen(mimeTypesFileName, "r");
     if (f == NULL)
     {
-        printf("Error opening mime types file. Setting defaults.\n");
-        entries = 3;
+        printf("Mime types file not found. Setting defaults.\n");
+        entries = 6;
         mimeArray = (mimeData *) calloc(entries, sizeof(mimeData));
         if (mimeArray == NULL) {
             printf("Errory while allocating mime types Array. Exiting.\n");
@@ -52,10 +52,16 @@
         }
         strcpy(mimeArray[0].ext, "html");
         strcpy(mimeArray[0].type, "text/html");
-        strcpy(mimeArray[1].ext, "gif");
-        strcpy(mimeArray[1].type, "image/gif");
-        strcpy(mimeArray[2].ext, "jpg");
-        strcpy(mimeArray[2].type, "image/jpg");
+        strcpy(mimeArray[1].ext, "htm");
+        strcpy(mimeArray[1].type, "text/html");
+        strcpy(mimeArray[2].ext, "gif");
+        strcpy(mimeArray[2].type, "image/gif");
+        strcpy(mimeArray[3].ext, "jpg");
+        strcpy(mimeArray[3].type, "image/jpg");
+        strcpy(mimeArray[4].ext, "png");
+        strcpy(mimeArray[4].type, "image/png");
+        strcpy(mimeArray[5].ext, "php");
+        strcpy(mimeArray[5].type, "application/x-httpd-php");
         mimeEntries = entries;
         return -1;
     }
