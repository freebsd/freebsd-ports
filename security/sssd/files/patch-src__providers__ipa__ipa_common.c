--- src/providers/ipa/ipa_common.c.orig	2020-03-17 13:31:28 UTC
+++ src/providers/ipa/ipa_common.c
@@ -49,7 +49,7 @@ int ipa_get_options(TALLOC_CTX *memctx,
     char *realm;
     char *ipa_hostname;
     int ret;
-    char hostname[HOST_NAME_MAX + 1];
+    char hostname[_POSIX_HOST_NAME_MAX + 1];
 
     opts = talloc_zero(memctx, struct ipa_options);
     if (!opts) return ENOMEM;
@@ -79,14 +79,14 @@ int ipa_get_options(TALLOC_CTX *memctx,
 
     ipa_hostname = dp_opt_get_string(opts->basic, IPA_HOSTNAME);
     if (ipa_hostname == NULL) {
-        ret = gethostname(hostname, sizeof(hostname));
+        ret = gethostname(hostname, _POSIX_HOST_NAME_MAX);
         if (ret != EOK) {
             DEBUG(SSSDBG_CRIT_FAILURE, "gethostname failed [%d][%s].\n", errno,
                       strerror(errno));
             ret = errno;
             goto done;
         }
-        hostname[HOST_NAME_MAX] = '\0';
+        hostname[_POSIX_HOST_NAME_MAX] = '\0';
         DEBUG(SSSDBG_TRACE_ALL, "Setting ipa_hostname to [%s].\n", hostname);
         ret = dp_opt_set_string(opts->basic, IPA_HOSTNAME, hostname);
         if (ret != EOK) {
