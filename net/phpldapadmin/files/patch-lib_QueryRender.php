--- lib/QueryRender.php.orig	2021-12-12 02:35:51 UTC
+++ lib/QueryRender.php
@@ -280,7 +280,7 @@ class QueryRender extends PageRender {
 
 						# Iterate over each attribute for this entry
 						foreach (explode(',',$ado) as $attr) {
-							$attr = strtolower($attr);
+							$attr = strtolower((string) $attr);
 
 							# Ignore DN, we've already displayed it.
 							if ($attr == 'dn')
@@ -379,7 +379,7 @@ class QueryRender extends PageRender {
 
 							# Special case for DNs
 							if ($attr == 'dn') {
-								$dn_display = strlen($dndetails['dn']) > 40
+								$dn_display = strlen((string) $dndetails['dn']) > 40
 									? sprintf('<acronym title="%s">%s...</acronym>',htmlspecialchars($dndetails['dn']),htmlspecialchars(substr($dndetails['dn'],0,40)))
 									: htmlspecialchars($dndetails['dn']);
 
@@ -461,7 +461,7 @@ class QueryRender extends PageRender {
 		$results = array();
 
 		foreach (explode(',',$this->template->getAttrDisplayOrder()) as $attr)
-			$results[strtolower($attr)] = $attribute_factory->newAttribute($attr,array('values'=>array()),$this->getServerID());
+			$results[strtolower((string) $attr)] = $attribute_factory->newAttribute($attr,array('values'=>array()),$this->getServerID());
 
 		return $results;
 	}
@@ -470,7 +470,7 @@ class QueryRender extends PageRender {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',129,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-		return preg_replace('/=/','.',base64_encode($dn));
+		return preg_replace('/=/','.',is_null(base64_encode($dn)? "":base64_encode($dn));
 	}
 
 	private function drawBaseTabs() {
