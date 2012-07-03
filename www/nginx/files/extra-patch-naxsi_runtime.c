--- ../naxsi-0.46-1/naxsi_src/naxsi_runtime.c.orig	2012-07-03 20:58:17.000000000 +0400
+++ ../naxsi-0.46-1/naxsi_src/naxsi_runtime.c	2012-07-03 21:01:32.000000000 +0400
@@ -116,7 +116,12 @@
     tmp_idx = 0;
     len = str->len;
     while 
-#if defined nginx_version && (nginx_version > 1001011)
+#if defined nginx_version && (nginx_version > 1002001)
+      (tmp_idx < len && 
+       (match = pcre_exec(rl->br->rx->regex->code, 0, 
+			  (const char *) str->data, str->len, tmp_idx, 0, 
+			  captures, 6)) >= 0)
+#elif defined nginx_version && ((nginx_version > 1001011) && (nginx_version <= 1002001))
       (tmp_idx < len && 
        (match = pcre_exec(rl->br->rx->regex->pcre, 0, 
 			  (const char *) str->data, str->len, tmp_idx, 0, 
