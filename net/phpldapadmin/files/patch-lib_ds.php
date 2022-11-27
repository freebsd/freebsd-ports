--- lib/ds.php.orig	2021-12-12 02:35:51 UTC
+++ lib/ds.php
@@ -371,7 +371,7 @@ abstract class DS {
 				$replacement = $this->getValue('login', 'sasl_dn_replacement');
 
 				if ($regex && $replacement) {
-					$userDN = preg_replace($regex, $replacement, $_SERVER['REMOTE_USER']);
+					$userDN = preg_replace($regex, $replacement,is_null( $_SERVER['REMOTE_USER'])? "": $_SERVER['REMOTE_USER']);
 
 					$CACHE[$this->index][$method] = $this->login($userDN, '', $method);
 
@@ -437,7 +437,7 @@ abstract class DS {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',17,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-		if (! trim($this->getLogin(null)) && $_SESSION[APPCONFIG]->getValue('appearance','anonymous_bind_implies_read_only'))
+		if (! trim((string) $this->getLogin(null)) && $_SESSION[APPCONFIG]->getValue('appearance','anonymous_bind_implies_read_only'))
 			return true;
 		else
 			return $this->getValue('server','read_only');
@@ -691,7 +691,7 @@ class Datastore {
 			debug_log('Entered (%%)',17,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
 		# If no index defined, then pick the lowest one.
-		if (is_null($index) || ! trim($index) || ! is_numeric($index))
+		if (is_null($index) || ! trim((string) $index) || ! is_numeric($index))
 			$index = min($this->GetServerList())->getIndex();
 
 		if (! isset($this->objects[$index]))
