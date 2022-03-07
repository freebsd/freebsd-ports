--- lib/ds_ldap.php.orig	2021-12-12 02:35:51 UTC
+++ lib/ds_ldap.php
@@ -1768,7 +1768,7 @@ class ldap extends DS {
 			ksort($return);
 
 			# cache the schema to prevent multiple schema fetches from LDAP server
-			set_cached_item($this->index,'schema','objectclasses',$return);
+			set_cached_item($this->index,$return,'schema','objectclasses');
 		}
 
 		if (DEBUG_ENABLED)
@@ -1953,7 +1953,7 @@ class ldap extends DS {
 			$return = $attrs;
 
 			# cache the schema to prevent multiple schema fetches from LDAP server
-			set_cached_item($this->index,'schema','attributes',$return);
+			set_cached_item($this->index,$return,'schema','attributes');
 		}
 
 		if (DEBUG_ENABLED)
@@ -2029,7 +2029,7 @@ class ldap extends DS {
 			$return = $rules;
 
 			# cache the schema to prevent multiple schema fetches from LDAP server
-			set_cached_item($this->index,'schema','matchingrules',$return);
+			set_cached_item($this->index,$return,'schema','matchingrules');
 		}
 
 		if (DEBUG_ENABLED)
@@ -2078,7 +2078,7 @@ class ldap extends DS {
 			ksort($return);
 
 			# cache the schema to prevent multiple schema fetches from LDAP server
-			set_cached_item($this->index,'schema','syntaxes',$return);
+			set_cached_item($this->index,$return,'schema','syntaxes');
 		}
 
 		if (DEBUG_ENABLED)
