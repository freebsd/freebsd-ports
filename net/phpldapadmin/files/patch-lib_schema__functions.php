--- lib/schema_functions.php.orig	2023-04-01 13:46:16 UTC
+++ lib/schema_functions.php
@@ -734,6 +734,8 @@ class AttributeType extends SchemaItem {
 	# This attribute has been forced a MAY attribute by the configuration.
 	private $forced_as_may = false;
 
+	private $is_obsolete;
+
 	/**
 	 * Creates a new AttributeType object from a raw LDAP AttributeType string.
 	 */
