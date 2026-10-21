--- document-server-package/common/documentserver/nginx/includes/ds-docservice.conf.m4.orig	2026-10-11 09:45:15 UTC
+++ document-server-package/common/documentserver/nginx/includes/ds-docservice.conf.m4
@@ -1,3 +1,12 @@
+# FreeBSD NOTE: static gzip (see the gzip_static settings below) is enabled
+# by default. It is re-enabled automatically whenever
+# documentserver-static-gzip or documentserver-generate-allfonts runs.
+# That happens after installing or upgrading this package, and when fonts
+# are added or removed. Edits that turn it off will be overwritten.
+# To disable it permanently, delete the directive lines entirely; the
+# scripts only change lines that already exist.
+#
+
 #welcome page
 location = / {
   add_header Strict-Transport-Security $hsts_header always;
@@ -16,13 +25,13 @@
 location ~ ^(\/[\d]+\.[\d]+\.[\d]+[\.|-][\w]+)?\/(web-apps\/apps\/api\/documents\/api\.js)$ {
   expires off;
   add_header Cache-Control "no-store, no-cache, must-revalidate";
-  # gzip_static on;
+  gzip_static on;
   alias  M4_DS_ROOT/$2;
 }
 
 location ~ ^(\/[\d]+\.[\d]+\.[\d]+[\.|-][\w]+)?\/(document_editor_service_worker.js)$ {
   add_header Cache-Control "public, max-age=31536000, immutable" always;
-  # gzip_static on;
+  gzip_static on;
   alias  M4_DS_ROOT/sdkjs/common/serviceworker/$2;
 }
 
@@ -30,7 +39,7 @@
 location ~ ^(\/[\d]+\.[\d]+\.[\d]+[\.|-][\w]+)?\/(web-apps)(\/.*\.json)$ {
   add_header Cache-Control "public, max-age=31536000, immutable" always;
   error_log M4_DEV_NULL crit;
-  # gzip_static on;
+  gzip_static on;
   alias M4_DS_ROOT/$2$3;
 }
 
@@ -38,13 +47,13 @@
 location ~ ^(\/[\d]+\.[\d]+\.[\d]+[\.|-][\w]+)?\/(sdkjs-plugins)(\/.*\.json)$ {
   add_header Cache-Control "public, max-age=31536000, immutable" always;
   error_log M4_DEV_NULL crit;
-  # gzip_static on;
+  gzip_static on;
   alias M4_DS_ROOT/$2$3;
 }
 
 location ~ ^(\/[\d]+\.[\d]+\.[\d]+[\.|-][\w]+)?\/(web-apps|sdkjs|sdkjs-plugins|fonts|dictionaries)(\/.*)$ {
   add_header Cache-Control "public, max-age=31536000, immutable" always;
-  # gzip_static on;
+  gzip_static on;
   alias M4_DS_ROOT/$2$3;
 }
 
@@ -85,7 +94,7 @@
 location ~ ^(\/[\d]+\.[\d]+\.[\d]+[\.|-][\w]+)?\/(meta\/formats)$ {
   add_header Cache-Control "public, max-age=31536000, immutable" always;
   default_type application/json;
-  # gzip_static on;
+  gzip_static on;
   alias M4_DS_ROOT/document-formats/onlyoffice-docs-formats.json;
 }
 
