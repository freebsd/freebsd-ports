--- src/host.c.orig	Mon May 12 15:39:19 2003
+++ src/host.c	Fri Jun 20 14:54:12 2003
@@ -817,8 +817,8 @@
     int rc;
     uschar *save = deliver_domain;
     deliver_domain = h->name;   /* set $domain */
-    rc = match_isinlist(string_copylc(h->name), &hosts_treat_as_local, 0, NULL,
-      NULL, MCL_DOMAIN, TRUE, NULL);
+    rc = match_isinlist(string_copylc(h->name), &hosts_treat_as_local, 0,
+      &domainlist_anchor, NULL, MCL_DOMAIN, TRUE, NULL);
     deliver_domain = save;
     if (rc == OK) goto FOUND_LOCAL;
     }
