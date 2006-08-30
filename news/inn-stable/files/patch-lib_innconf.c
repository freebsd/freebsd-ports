--- lib/innconf.c.orig	Mon Mar 20 04:14:57 2006
+++ lib/innconf.c	Sat Aug 26 00:22:04 2006
@@ -395,7 +395,7 @@
 
     if (GetFQDN(innconf->domain) == NULL) {
         warn("hostname does not resolve or domain not set in inn.conf");
-        okay = false;
+/*        okay = false; */
     }
     if (innconf->mta == NULL) {
         warn("must set mta in inn.conf");
