--- src/main/util.c.orig	Mon Apr  2 13:21:27 2001
+++ src/main/util.c	Mon Apr  2 13:21:28 2001
@@ -2048,12 +2048,14 @@
     int x;
 
     if (!strchr(p->h_name, '.')) {
-	for (x = 0; p->h_aliases[x]; ++x) {
-	    if (strchr(p->h_aliases[x], '.') &&
-		(!strncasecmp(p->h_aliases[x], p->h_name, strlen(p->h_name))))
-		return ap_pstrdup(a, p->h_aliases[x]);
-	}
-	return NULL;
+        if (p->h_aliases) {
+        	for (x = 0; p->h_aliases[x]; ++x) {
+                if (p->h_aliases[x] && strchr(p->h_aliases[x], '.') &&
+            		(!strncasecmp(p->h_aliases[x], p->h_name, strlen(p->h_name))))
+		            return ap_pstrdup(a, p->h_aliases[x]);
+            }
+	    }
+	    return NULL;
     }
     return ap_pstrdup(a, (void *) p->h_name);
 }
@@ -2077,7 +2079,6 @@
 	ap_log_error(APLOG_MARK, APLOG_WARNING, NULL,
 	             "%s: gethostname() failed to determine ServerName\n",
                      ap_server_argv0);
-	server_hostname = ap_pstrdup(a, "127.0.0.1");
     }
     else
     {
