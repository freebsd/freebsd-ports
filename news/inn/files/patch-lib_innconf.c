--- lib/innconf.c.orig	2015-09-12 15:25:22.000000000 +0200
+++ lib/innconf.c	2015-09-21 21:15:18.446435000 +0200
@@ -473,7 +473,7 @@ innconf_validate(struct config_group *gr
 
     if (GetFQDN(innconf->domain) == NULL) {
         warn("hostname does not resolve or domain not set in inn.conf");
-        okay = false;
+/*        okay = false; */
     }
     if (innconf->mta == NULL) {
         warn("must set mta in inn.conf");
