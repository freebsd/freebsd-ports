--- src/expand.c.orig	Mon Aug 18 14:52:54 2003
+++ src/expand.c	Fri Aug 29 17:51:12 2003
@@ -1462,6 +1462,9 @@
   if (yield != NULL)
     {
     int rc;
+
+    if ( sub[2] == NULL ) sub[3] = NULL;
+
     rc = auth_call_saslauthd(sub[0], sub[1], sub[2], sub[3],
       &expand_string_message);
     if (rc == ERROR || rc == DEFER) return NULL;
