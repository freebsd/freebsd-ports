--- src/conf.c.orig	2011-02-09 11:55:12.000000000 -0800
+++ src/conf.c	2011-02-09 11:56:02.000000000 -0800
@@ -1046,8 +1046,8 @@
                 return -1;
         port = (int) get_long_arg (line, &match[7]);
 
-        if (match[9].rm_so != -1) {
-                domain = get_string_arg (line, &match[9]);
+        if (match[10].rm_so != -1) {
+                domain = get_string_arg (line, &match[10]);
                 if (domain) {
                         upstream_add (ip, port, domain, &conf->upstream_list);
                         safefree (domain);
