--- src/sitestore.c.orig	2006-02-04 10:18:08 UTC
+++ src/sitestore.c
@@ -340,8 +340,8 @@ static int end_element(void *userdata, int state,
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
