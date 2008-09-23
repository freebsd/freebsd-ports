--- mib/parse.c.orig	2007-05-26 17:42:33.000000000 -0700
+++ mib/parse.c	2008-09-18 10:42:58.000000000 -0700
@@ -4516,20 +4516,17 @@
 int
 add_mibdir(const char *dirname)
 {
-    FILE           *fp, *ip;
+    FILE           *fp;
     DIR            *dir, *dir2;
     const char     *oldFile = File;
     struct dirent  *file;
     char            token[MAXTOKEN], token2[MAXTOKEN];
-    char            tmpstr[300];
+    char            tmpstr[MAXPATHLEN];
     int             count = 0;
 
     DEBUGMSGTL(("parse-mibs", "Scanning directory %s\n", dirname));
 
     if ((dir = opendir(dirname))) {
-        snprintf(tmpstr, sizeof(tmpstr), "%s/.index", dirname);
-        tmpstr[ sizeof(tmpstr)-1 ] = 0;
-        ip = fopen(tmpstr, "w");
         while ((file = readdir(dir))) {
             /*
              * Only parse file names not beginning with a '.' 
@@ -4561,8 +4558,6 @@
                     if (get_token(fp, token2, MAXTOKEN) == DEFINITIONS) {
                         new_module(token, tmpstr);
                         count++;
-                        if (ip)
-                            fprintf(ip, "%s %s\n", token, file->d_name);
                     }
                     fclose(fp);
                 }
@@ -4570,8 +4565,6 @@
         }
         File = oldFile;
         closedir(dir);
-        if (ip)
-            fclose(ip);
         return (count);
     }
     return (-1);
