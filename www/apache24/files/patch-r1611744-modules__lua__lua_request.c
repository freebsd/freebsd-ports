backport for mod_lua: Don't quote values in cookies; Make IE happy again [#56734]
http://svn.apache.org/viewvc?view=revision&revision=1611744


--- ./modules/lua/lua_request.c.orig	2014-07-20 10:48:19.000000000 +0200
+++ ./modules/lua/lua_request.c	2014-07-20 10:48:46.000000000 +0200
@@ -2086,13 +2086,13 @@
     if (expires > 0) {
         rv = apr_rfc822_date(cdate, apr_time_from_sec(expires));
         if (rv == APR_SUCCESS) {
-            strexpires = apr_psprintf(r->pool, "Expires=\"%s\";", cdate);
+            strexpires = apr_psprintf(r->pool, "Expires=%s;", cdate);
         }
     }
     
     /* Create path segment */
     if (path != NULL && strlen(path) > 0) {
-        strpath = apr_psprintf(r->pool, "Path=\"%s\";", path);
+        strpath = apr_psprintf(r->pool, "Path=%s;", path);
     }
     
     /* Create domain segment */
