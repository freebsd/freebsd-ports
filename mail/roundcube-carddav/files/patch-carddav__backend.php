--- carddav_backend.php.orig	2018-05-28 06:30:30 UTC
+++ carddav_backend.php
@@ -716,9 +716,7 @@ EOF
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
