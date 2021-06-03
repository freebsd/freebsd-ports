--- src/openvpn/options.c.orig	2021-04-21 04:02:50 UTC
+++ src/openvpn/options.c
@@ -5319,7 +5319,7 @@ add_option(struct options *options,
         {
             /* only message-related ECHO are logged, since other ECHOs
              * can potentially include security-sensitive strings */
-            if (strncmp(p[1], "msg", 3) == 0)
+            if (p[1] && strncmp(p[1], "msg", 3) == 0)
             {
                 msg(M_INFO, "%s:%s",
                     pull_mode ? "ECHO-PULL" : "ECHO",
