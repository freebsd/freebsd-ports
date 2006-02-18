--- file.c.orig	Sun Feb 19 01:37:44 2006
+++ file.c	Sun Feb 19 01:39:59 2006
@@ -262,7 +262,8 @@
 {
     return (type == NULL || type[0] == '\0' ||
 	    strncasecmp(type, "text/", 5) == 0 ||
-	    strncasecmp(type, "message/", sizeof("message/") - 1) == 0);
+	    strncasecmp(type, "message/", sizeof("message/") - 1) == 0 ||
+	    IS_HTML(type));
 }
 
 static int
@@ -7891,7 +7892,7 @@
 	    uf->scheme = SCM_LOCAL;
     }
     UFhalfclose(uf);
-    uf->stream = newFileStream(f1, (void (*)())pclose);
+    uf->stream = newFileStream(f1, (void (*)())fclose);
 }
 
 static FILE *
