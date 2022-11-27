--- htdocs/add_oclass_form.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/add_oclass_form.php
@@ -36,7 +36,7 @@ $ldap['attrs']['must'] = array();
 
 foreach ($request['template']->getAttribute('objectclass')->getValues() as $oclass_name) {
 	# Exclude "top" if its there.
-	if (! strcasecmp('top',$oclass_name))
+	if (! strcasecmp('top',(string) $oclass_name))
 		continue;
 
 	if ($soc = $app['server']->getSchemaObjectClass($oclass_name))
