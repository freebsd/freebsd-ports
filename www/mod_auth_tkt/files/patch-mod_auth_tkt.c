--- a/src/mod_auth_tkt.c.orig	2009-07-10 16:46:51.000000000 +0900
+++ b/src/mod_auth_tkt.c	2015-01-27 12:14:50.163420705 +0900
@@ -6,6 +6,7 @@
 #include "http_config.h"
 #include "http_log.h"
 #include "http_core.h"
+#include "http_request.h"
 #include "http_protocol.h"
 #include "util_md5.h"
 #include "sha2.h"
@@ -439,10 +440,10 @@
 #endif
   AP_INIT_TAKE1("TKTAuthBackCookieName", ap_set_string_slot, 
     (void *)APR_OFFSETOF(auth_tkt_dir_conf, back_cookie_name),
-    OR_AUTHCFG, "name to use for back cookie (NULL for none)"),
+    OR_AUTHCFG, "name to use for back cookie (default: none)"),
   AP_INIT_TAKE1("TKTAuthBackArgName", ap_set_string_slot, 
     (void *)APR_OFFSETOF(auth_tkt_dir_conf, back_arg_name),
-    OR_AUTHCFG, "name to use for back url argument (NULL for none)"),
+    OR_AUTHCFG, "name to use for back url argument ('None' to not use)"),
   AP_INIT_FLAG("TKTAuthIgnoreIP", ap_set_flag_slot, 
     (void *)APR_OFFSETOF(auth_tkt_dir_conf, ignore_ip),
     OR_AUTHCFG, "whether to ignore remote IP address in ticket"),
@@ -467,19 +468,19 @@
   AP_INIT_TAKE1("TKTAuthSecretOld", setup_old_secret, 
     NULL, RSRC_CONF, "old/alternative secret key to check in digests"),
   AP_INIT_TAKE1("TKTAuthDigestType", setup_digest_type, 
-    NULL, RSRC_CONF, "digest type to use [MD5|SHA256|SHA512], default MD5"),
+    NULL, RSRC_CONF, "digest type to use [MD5|SHA256|SHA512], default: MD5"),
   AP_INIT_FLAG("TKTAuthGuestLogin", ap_set_flag_slot,
     (void *)APR_OFFSETOF(auth_tkt_dir_conf, guest_login),
     OR_AUTHCFG, "whether to log people in as guest if no other auth available"),
   AP_INIT_FLAG("TKTAuthGuestCookie", ap_set_flag_slot,
     (void *)APR_OFFSETOF(auth_tkt_dir_conf, guest_cookie),
-    OR_AUTHCFG, "whether to set a cookie when accepting guest users (default off)"),
+    OR_AUTHCFG, "whether to set a cookie when accepting guest users (default: off)"),
   AP_INIT_TAKE1("TKTAuthGuestUser", ap_set_string_slot, 
     (void *)APR_OFFSETOF(auth_tkt_dir_conf, guest_user),
     OR_AUTHCFG, "username to use for guest logins"),
   AP_INIT_FLAG("TKTAuthGuestFallback", ap_set_flag_slot,
     (void *)APR_OFFSETOF(auth_tkt_dir_conf, guest_fallback),
-    OR_AUTHCFG, "whether to fall back to guest on an expired ticket (default off)"),
+    OR_AUTHCFG, "whether to fall back to guest on an expired ticket (default: off)"),
   AP_INIT_ITERATE("TKTAuthDebug", set_auth_tkt_debug, 
     (void *)APR_OFFSETOF(auth_tkt_dir_conf, debug),
     OR_AUTHCFG, "debug level (1-3, higher for more debug output)"),
@@ -798,7 +799,11 @@
   unsigned char *buf2 = apr_palloc(r->pool, sconf->digest_sz + strlen(secret));
   int len = 0;
   char *digest = NULL;
+#if AP_MODULE_MAGIC_AT_LEAST(20111130,0)
+  char *remote_ip = conf->ignore_ip > 0 ? "0.0.0.0" : r->connection->client_ip;
+#else
   char *remote_ip = conf->ignore_ip > 0 ? "0.0.0.0" : r->connection->remote_ip;
+#endif
   unsigned long ip;
   struct in_addr ia;
   char *d;
@@ -1432,6 +1437,10 @@
     setup_digest_sz(sconf);
   }
 
+  /* Map "None" back_arg_name to NULL */
+  if (conf->back_arg_name && strcmp(conf->back_arg_name, "None") == 0)
+    conf->back_arg_name = NULL;
+
   /* Dump config if debugging */
   if (conf->debug >= 2)
     dump_config(r, sconf, conf);
@@ -1575,7 +1584,11 @@
 auth_tkt_register_hooks (apr_pool_t *p)
 {
   ap_hook_post_config(auth_tkt_version, NULL, NULL, APR_HOOK_MIDDLE);
+#if AP_MODULE_MAGIC_AT_LEAST(20080403,1)
+  ap_hook_check_authn(auth_tkt_check, NULL, NULL, APR_HOOK_FIRST, AP_AUTH_INTERNAL_PER_CONF);
+#else
   ap_hook_check_user_id(auth_tkt_check, NULL, NULL, APR_HOOK_FIRST);
+#endif
 }
 
 /* Declare and populate the main module data structure */
@@ -1592,5 +1605,5 @@
 #endif
 
 /* 
- * vim:sw=2:sm
+ * vim:sw=2:sm:et
  */
