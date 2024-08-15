--- src/providers/ad/ad_common.c.orig	2020-03-17 13:31:28 UTC
+++ src/providers/ad/ad_common.c
@@ -420,7 +420,7 @@ ad_get_common_options(TALLOC_CTX *mem_ctx,
     char *server;
     char *realm;
     char *ad_hostname;
-    char hostname[HOST_NAME_MAX + 1];
+    char hostname[_POSIX_HOST_NAME_MAX + 1];
     char *case_sensitive_opt;
     const char *opt_override;
 
@@ -459,7 +459,7 @@ ad_get_common_options(TALLOC_CTX *mem_ctx,
      */
     ad_hostname = dp_opt_get_string(opts->basic, AD_HOSTNAME);
     if (ad_hostname == NULL) {
-        gret = gethostname(hostname, sizeof(hostname));
+        gret = gethostname(hostname, _POSIX_HOST_NAME_MAX);
         if (gret != 0) {
             ret = errno;
             DEBUG(SSSDBG_FATAL_FAILURE,
@@ -467,7 +467,7 @@ ad_get_common_options(TALLOC_CTX *mem_ctx,
                    strerror(ret));
             goto done;
         }
-        hostname[HOST_NAME_MAX] = '\0';
+        hostname[_POSIX_HOST_NAME_MAX] = '\0';
         DEBUG(SSSDBG_CONF_SETTINGS,
               "Setting ad_hostname to [%s].\n", hostname);
         ret = dp_opt_set_string(opts->basic, AD_HOSTNAME, hostname);
