--- ./src/providers/ipa/ipa_common.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/providers/ipa/ipa_common.c	2011-10-13 12:15:03.000000000 -0400
@@ -191,7 +191,7 @@
     char *ipa_hostname;
     int ret;
     int i;
-    char hostname[HOST_NAME_MAX + 1];
+    char hostname[_POSIX_HOST_NAME_MAX + 1];
 
     opts = talloc_zero(memctx, struct ipa_options);
     if (!opts) return ENOMEM;
@@ -220,14 +220,14 @@
 
     ipa_hostname = dp_opt_get_string(opts->basic, IPA_HOSTNAME);
     if (ipa_hostname == NULL) {
-        ret = gethostname(hostname, HOST_NAME_MAX);
+        ret = gethostname(hostname, _POSIX_HOST_NAME_MAX);
         if (ret != EOK) {
             DEBUG(1, ("gethostname failed [%d][%s].\n", errno,
                       strerror(errno)));
             ret = errno;
             goto done;
         }
-        hostname[HOST_NAME_MAX] = '\0';
+        hostname[_POSIX_HOST_NAME_MAX] = '\0';
         DEBUG(9, ("Setting ipa_hostname to [%s].\n", hostname));
         ret = dp_opt_set_string(opts->basic, IPA_HOSTNAME, hostname);
         if (ret != EOK) {
