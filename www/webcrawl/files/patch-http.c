--- http.c	Fri Apr 30 12:04:19 1999
+++ http.c.new	Tue Nov  6 13:28:06 2001
@@ -106,8 +106,7 @@
 	alarm(options.timeout);
     }
 
-    strcpy (szRequest, "GET /"); strcat (szRequest, pszFile);
-    strcat (szRequest, " HTTP/1.0\n");
+    snprintf (szRequest, 512, "GET http://%s/%s HTTP/1.0\n", pszHost, pszFile);
     strcat (szRequest, "User-Agent: "); 
     strcat (szRequest, options.userAgent);
     strcat (szRequest, "\n\n");
