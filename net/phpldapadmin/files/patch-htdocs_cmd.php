--- htdocs/cmd.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/cmd.php
@@ -41,7 +41,7 @@ if (DEBUG_ENABLED)
 $www['page'] = new page($app['server']->getIndex());
 
 # See if we can render the command
-if (trim($www['cmd'])) {
+if (trim((string) $www['cmd'])) {
 	# If this is a READ-WRITE operation, the LDAP server must not be in READ-ONLY mode.
 	if ($app['server']->isReadOnly() && ! in_array(get_request('cmd','REQUEST'),$app['readwrite_cmds']))
 		error(_('You cannot perform updates while server is in read-only mode'),'error','index.php');
