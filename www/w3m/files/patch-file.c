--- file.c	Sun Oct  9 22:12:16 2005
+++ file.c	Sun Oct  9 22:11:10 2005
@@ -262,7 +262,8 @@
 {
     return (type == NULL || type[0] == '\0' ||
 	    strncasecmp(type, "text/", 5) == 0 ||
-	    strncasecmp(type, "message/", sizeof("message/") - 1) == 0);
+	    strncasecmp(type, "message/", sizeof("message/") - 1) == 0 ||
+	    IS_HTML(type));
 }
 
 static int
