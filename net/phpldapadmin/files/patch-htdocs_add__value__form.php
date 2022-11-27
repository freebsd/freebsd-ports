--- htdocs/add_value_form.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/add_value_form.php
@@ -32,12 +32,12 @@ if ($request['attribute']->isReadOnly())
 */
 
 # Render the form
-if (! strcasecmp($request['attr'],'objectclass') || get_request('meth','REQUEST') != 'ajax') {
+if (! strcasecmp((string) $request['attr'],'objectclass') || get_request('meth','REQUEST') != 'ajax') {
 	# Render the form.
 	$request['page']->drawTitle(sprintf('%s <b>%s</b> %s <b>%s</b>',_('Add new'),htmlspecialchars($request['attr']),_('value to'),htmlspecialchars(get_rdn($request['dn']))));
 	$request['page']->drawSubTitle();
 
-	if (! strcasecmp($request['attr'],'objectclass')) {
+	if (! strcasecmp((string) $request['attr'],'objectclass')) {
 		echo '<form action="cmd.php" method="post" class="new_value" id="entry_form">';
 		echo '<div>';
 		echo '<input type="hidden" name="cmd" value="add_oclass_form" />';
@@ -91,12 +91,12 @@ if (! strcasecmp($request['attr'],'objectclass') || ge
 	printf('<td class="top">%s</td>',_('Enter the value(s) you would like to add:'));
 	echo '<td>';
 
-	if (! strcasecmp($request['attr'],'objectclass')) {
+	if (! strcasecmp((string) $request['attr'],'objectclass')) {
 		# If our attr is an objectClass, fetch all available objectClasses and remove those from the list that are already defined in the entry
 		$socs = $app['server']->SchemaObjectClasses();
 
 		foreach ($request['attribute']->getValues() as $oclass)
-			unset($socs[strtolower($oclass)]);
+			unset($socs[strtolower((string) $oclass)]);
 
 		# Draw objectClass selection
 		echo '<table border="0">';
