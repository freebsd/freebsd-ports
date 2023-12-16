--- lib/xmlTemplates.php.orig	2023-04-01 13:46:16 UTC
+++ lib/xmlTemplates.php
@@ -122,7 +122,7 @@ abstract class xmlTemplates {
 
 					# Ignore any files that are not the predefined custom files.
 					if ($_SESSION[APPCONFIG]->getValue('appearance','custom_templates_only')
-						&& ! preg_match("/^${custom_prefix}/",$file))
+						&& ! preg_match("/^{$custom_prefix}/",$file))
 						continue;
 
 					$filename = sprintf('%s/%s',$dir,$file);
