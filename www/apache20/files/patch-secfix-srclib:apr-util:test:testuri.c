--- srclib/apr-util/test/testuri.c
+++ srclib/apr-util/test/testuri.c
@@ -36,6 +37,10 @@
 
 struct aup_test aup_tests[] =
 {
+    { "http://[/::1]/index.html", APR_EGENERAL },
+    { "http://[", APR_EGENERAL },
+    { "http://[?::1]/index.html", APR_EGENERAL },
+
     {
         "http://127.0.0.1:9999/asdf.html",
         0, "http", "127.0.0.1:9999", NULL, NULL, "127.0.0.1", "9999", "/asdf.html", NULL, NULL, 9999
--- srclib/apr-util/uri/apr_uri.c
+++ srclib/apr-util/uri/apr_uri.c
@@ -307,11 +307,11 @@
         if (*hostinfo == '[') {
             v6_offset1 = 1;
             v6_offset2 = 2;
-            s = uri;
-            do {
-                --s;
-            } while (s >= hostinfo && *s != ':' && *s != ']');
-            if (s < hostinfo || *s == ']') {
+            s = memchr(hostinfo, ']', uri - hostinfo);
+            if (s == NULL) {
+                return APR_EGENERAL;
+            }
+            if (*++s != ':') {
                 s = NULL; /* no port */
             }
         }

