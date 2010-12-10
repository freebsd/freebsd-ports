--- lib/Net/SMS/Clickatell.pm.orig	2004-11-30 16:20:13.000000000 +0000
+++ lib/Net/SMS/Clickatell.pm	2010-12-02 00:57:10.000000000 +0000
@@ -89,7 +89,7 @@
   if(!exists $args{BaseURL}) {
     # BaseURL argument wasn't passed. Set it to default.
     # Check if we have to use SSL.
-    if(exists $args{UseSSL}) {
+    if($args{UseSSL}) {
       $args{BaseURL} = 'https://api.clickatell.com';
     } else {
       $args{BaseURL} = 'http://api.clickatell.com';
@@ -97,7 +97,7 @@
   } else {
     # Set BaseURL property value.
     # Check if we have to use SSL.
-    if(exists $args{UseSSL}) {
+    if($args{UseSSL}) {
       $args{BaseURL} = 'https://'.$args{BaseURL};
     } else {
       $args{BaseURL} = 'http://'.$args{BaseURL};
