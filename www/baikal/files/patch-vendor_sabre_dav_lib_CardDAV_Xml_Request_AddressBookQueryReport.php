--- vendor/sabre/dav/lib/CardDAV/Xml/Request/AddressBookQueryReport.php.orig	2017-04-13 09:07:30 UTC
+++ vendor/sabre/dav/lib/CardDAV/Xml/Request/AddressBookQueryReport.php
@@ -29,6 +29,13 @@ class AddressBookQueryReport implements 
     public $properties;
 
     /**
+     * An array with requested vcard properties.
+     *
+     * @var array
+     */
+    public $addressDataProperties = [];
+
+    /**
      * List of property/component filters.
      *
      * This is an array with filters. Every item is a property filter. Every
