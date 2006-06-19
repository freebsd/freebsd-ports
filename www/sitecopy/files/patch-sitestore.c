--- src/sitestore.c.orig	Mon Jun 19 12:07:52 2006
+++ src/sitestore.c	Mon Jun 19 12:08:24 2006
@@ -340,8 +340,8 @@
 	}
 	break;
     case SITE_ELM_size:
-	doc->stored.size = strtol(cdata, NULL, 10);
-	if (doc->stored.size == LONG_MAX) {
+	doc->stored.size = strtoll(cdata, NULL, 10);
+	if (doc->stored.size == LLONG_MAX) {
         }
 	break;
     case SITE_ELM_protection:
