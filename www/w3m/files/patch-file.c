--- file.c.orig	Tue Jan  2 22:11:50 2007
+++ file.c	Tue Jan  2 22:14:11 2007
@@ -262,7 +262,8 @@
 {
     return (type == NULL || type[0] == '\0' ||
 	    strncasecmp(type, "text/", 5) == 0 ||
-	    strncasecmp(type, "message/", sizeof("message/") - 1) == 0);
+	    strncasecmp(type, "message/", sizeof("message/") - 1) == 0 ||
+	    IS_HTML(type));
 }
 
 static int
@@ -7799,7 +7800,7 @@
 	ans = inputChar(prompt);
     }
     else {
-	printf(prompt);
+	printf("%s", prompt);
 	fflush(stdout);
 	ans = Strfgets(stdin)->ptr;
     }
@@ -7891,7 +7892,7 @@
 	    uf->scheme = SCM_LOCAL;
     }
     UFhalfclose(uf);
-    uf->stream = newFileStream(f1, (void (*)())pclose);
+    uf->stream = newFileStream(f1, (void (*)())fclose);
 }
 
 static FILE *
