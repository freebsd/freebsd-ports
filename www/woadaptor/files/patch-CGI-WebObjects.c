--- CGI/WebObjects.c.orig	Sun May 13 01:12:59 2007
+++ CGI/WebObjects.c	Sun May 13 01:23:31 2007
@@ -254,19 +254,7 @@
        *	extract WebObjects application name from URI
        */
 
-      qs = getenv("QUERY_STRING");
-      if (qs) {
-         qs_len = strlen(qs);
-      } else {
-         qs_len = 0;
-      }
-
-      if (qs_len > 0) {
-         /* Make room for query string and "?" */
-         url = WOMALLOC(strlen(path_info) + strlen(script_name) + 1 + qs_len + 2);
-      } else {
-         url = WOMALLOC(strlen(path_info) + strlen(script_name) + 1);
-      }
+      url = WOMALLOC(strlen(path_info) + strlen(script_name) + 1);
       strcpy(url, script_name);
       strcat(url, path_info);
       WOLog(WO_INFO,"<CGI> new request: %s",url);
@@ -371,11 +359,14 @@
       }
 
       /* Always get the query string */
-      /* Don't add ? if the query string is empty. */
+      qs = getenv("QUERY_STRING");
+      if (qs) {
+         qs_len = strlen(qs);
+      } else {
+         qs_len = 0;
+      }
+
       if (qs_len > 0) {
-         /* Add the query string to the full URL - useful for debugging */
-         strcat(url, "?");
-         strcat(url, qs);
          wc.queryString.start = qs;
          wc.queryString.length = qs_len;
          WOLog(WO_INFO,"<CGI> new request with Query String: %s", qs);
