--- carddav_backend.php.orig	2017-06-12 12:21:39 UTC
+++ carddav_backend.php
@@ -694,9 +694,7 @@ EOF
 <C:addressbook-multiget xmlns:D="DAV:" xmlns:C="urn:ietf:params:xml:ns:carddav">
 <D:prop>
     <D:getetag/>
-    <C:address-data>
-        <C:allprop/>
-    </C:address-data>
+    <C:address-data/>
 </D:prop>
 $hrefstr
 </C:addressbook-multiget>
