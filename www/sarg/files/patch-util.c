--- util.c.orig	Mon Oct  4 00:37:03 2004
+++ util.c	Mon Nov 15 17:27:48 2004
@@ -483,6 +483,25 @@
  
 }
 
+void my_mkdir(char *name)
+{
+   char w0[255];
+   char w1[255];
+   char w2[255];
+
+   strcpy(w0,name);
+   strcpy(w2,"/");
+   getword(w1,w0,'/');
+   while(strstr(w0,"/") != 0) {
+      getword(w1,w0,'/');
+      strcat(w2,w1);
+      mkdir(w2,0755);
+      strcat(w2,"/");
+   }
+   strcat(w2,w0);
+   mkdir(w2,0755);
+}
+
 void vrfydir(char *dir, char *dirname, char *per1, char *addr, char *site, char *us, char *form)
 {
    FILE *img_in, *img_ou;
@@ -902,25 +921,6 @@
       fputs(html,fp_ou);
       fputs("<table>\n",fp_ou);
    }
-}
-
-void my_mkdir(char *name)
-{
-   char w0[255];
-   char w1[255];
-   char w2[255];
-
-   strcpy(w0,name);
-   strcpy(w2,"/");
-   getword(w1,w0,'/');
-   while(strstr(w0,"/") != 0) {
-      getword(w1,w0,'/');
-      strcat(w2,w1);
-      mkdir(w2,0755);
-      strcat(w2,"/");
-   }
-   strcat(w2,w0);
-   mkdir(w2,0755);
 }
 
 char url_module(char *url, char *w2)
