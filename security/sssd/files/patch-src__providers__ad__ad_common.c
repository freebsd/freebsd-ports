diff --git src/providers/ad/ad_common.c src/providers/ad/ad_common.c
index 0d154ca57..407d37a37 100644
--- src/providers/ad/ad_common.c
+++ src/providers/ad/ad_common.c
@@ -419,7 +419,7 @@ ad_get_common_options(TALLOC_CTX *mem_ctx,
     char *server;
     char *realm;
     char *ad_hostname;
-    char hostname[HOST_NAME_MAX + 1];
+    char hostname[_POSIX_HOST_NAME_MAX + 1];
     char *case_sensitive_opt;
     const char *opt_override;
 
@@ -458,7 +458,7 @@ ad_get_common_options(TALLOC_CTX *mem_ctx,
      */
     ad_hostname = dp_opt_get_string(opts->basic, AD_HOSTNAME);
     if (ad_hostname == NULL) {
-        gret = gethostname(hostname, sizeof(hostname));
+        gret = gethostname(hostname, _POSIX_HOST_NAME_MAX);
         if (gret != 0) {
             ret = errno;
             DEBUG(SSSDBG_FATAL_FAILURE,
@@ -466,7 +466,7 @@ ad_get_common_options(TALLOC_CTX *mem_ctx,
                    strerror(ret));
             goto done;
         }
-        hostname[HOST_NAME_MAX] = '\0';
+        hostname[_POSIX_HOST_NAME_MAX] = '\0';
         DEBUG(SSSDBG_CONF_SETTINGS,
               "Setting ad_hostname to [%s].\n", hostname);
         ret = dp_opt_set_string(opts->basic, AD_HOSTNAME, hostname);
