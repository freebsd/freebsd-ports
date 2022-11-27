--- htdocs/copy.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/copy.php
@@ -21,7 +21,7 @@ $ldap['SRC'] = $_SESSION[APPCONFIG]->getServer(get_req
 $ldap['DST'] = $_SESSION[APPCONFIG]->getServer(get_request('server_id_dst'));
 
 # Error checking
-if (! trim($request['dnDST']))
+if (! trim((string) $request['dnDST']))
 	error(_('You left the destination DN blank.'),'error','index.php');
 
 if ($ldap['DST']->isReadOnly())
