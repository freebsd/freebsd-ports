--- lib/innconf.c.orig	2023-04-16 19:50:54 UTC
+++ lib/innconf.c
@@ -447,17 +447,17 @@ innconf_validate(struct config_group *group)
     fqdn = inn_getfqdn(innconf->domain);
     if (fqdn == NULL) {
         warn("hostname does not resolve or domain not set in inn.conf");
-        okay = false;
+/*        okay = false; */
     }
     if (innconf->domain != NULL && !IsValidDomain(innconf->domain)) {
         warn("domain in inn.conf contains invalid characters not suitable for "
              "Message-IDs");
-        okay = false;
+/*        okay = false; */
     }
     if (innconf->domain == NULL && !IsValidDomain(fqdn)) {
         warn("the FQDN of the server contains invalid characters not suitable "
              "for Message-IDs");
-        okay = false;
+/*        okay = false; */
     }
     free(fqdn);
 
