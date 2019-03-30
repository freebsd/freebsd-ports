--- svc.c.orig	2018-05-11 10:16:05 UTC
+++ svc.c
@@ -273,6 +273,7 @@ addr2str(char *const res, const int res_len, const str
     char    buf[MAXBUF];
     int     port;
     void    *src;
+    char    *p = buf;
 
     memset(res, 0, res_len);
 #ifdef  HAVE_INET_NTOP
@@ -298,10 +299,15 @@ addr2str(char *const res, const int res_len, const str
         port = 0;
         break;
     }
-    if(no_port)
-        snprintf(res, res_len, "%s", buf);
+    // Strip off the IPv6 prefix
+    if (strncmp(buf, "::ffff:", 7) == 0)
+    {
+        p = buf + 7;
+    }
+    if (no_port) 
+        snprintf(res, res_len, "%s", p);
     else
-        snprintf(res, res_len, "%s:%d", buf, port);
+        snprintf(res, res_len, "%s:%d", p, port);
 #else
 #error "Pound needs inet_ntop()"
 #endif
