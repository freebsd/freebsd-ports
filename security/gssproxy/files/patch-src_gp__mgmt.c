--- src/gp_mgmt.c.orig	2024-03-11 21:18:04 UTC
+++ src/gp_mgmt.c
@@ -273,9 +273,8 @@ done:
 
 done:
     if (ret) {
-        char errstr[128]; /* reasonable error str length */
         GPDEBUGN(3, "%s: Failed to set up krb5 tracing thread: [%s](%d)\n",
-                    __func__, strerror_r(ret, errstr, 128), ret);
+                    __func__, gp_strerror(ret), ret);
         free_k5tracer();
     }
     return;
