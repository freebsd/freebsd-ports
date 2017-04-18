--- vendor/sabre/dav/lib/CardDAV/Xml/Filter/AddressData.php.orig	2017-04-13 09:07:03 UTC
+++ vendor/sabre/dav/lib/CardDAV/Xml/Filter/AddressData.php
@@ -51,6 +51,10 @@ class AddressData implements XmlDeserial
             'version'     => $reader->getAttribute('version') ?: '3.0',
         ];
 
+        $elems = (array)$reader->parseInnerTree();
+        $result['addressDataProperties'] = array_map(function($element) {
+            return $element['attributes']['name'];
+        }, $elems);
+
-        $reader->next();
         return $result;
 
