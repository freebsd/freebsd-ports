--- src/xitk/main.c.orig	Sun Jul 24 11:40:37 2005
+++ src/xitk/main.c	Thu Apr 20 01:03:46 2006
@@ -456,7 +456,7 @@
   int          len;
   char        *blanks = "     ";
 
-  printf(title);
+  printf("%s", title);
   
   sprintf(buffer, "%s", blanks);
   plugin = *plugins++;
@@ -469,7 +469,7 @@
       sprintf(buffer, "%s%s%s", buffer, (strlen(buffer) == strlen(blanks)) ? "" : ", ", plugin);
     }
     else {
-      printf(buffer);
+      printf("%s", buffer);
       printf(",\n");
       snprintf(buffer, sizeof(buffer), "%s%s", blanks, plugin);
     }
@@ -478,7 +478,7 @@
   }
   
   if(strlen(buffer))
-    printf(buffer);
+    printf("%s", buffer);
   
   printf(".\n\n");
 }
