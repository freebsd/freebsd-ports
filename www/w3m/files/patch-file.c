--- file.c.orig	Thu May 24 00:06:05 2007
+++ file.c	Sat Jun  9 12:44:09 2007
@@ -262,7 +262,8 @@
 {
     return (type == NULL || type[0] == '\0' ||
 	    strncasecmp(type, "text/", 5) == 0 ||
-	    strncasecmp(type, "message/", sizeof("message/") - 1) == 0);
+	    strncasecmp(type, "message/", sizeof("message/") - 1) == 0 ||
+	    IS_HTML(type));
 }
 
 static int
