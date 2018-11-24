--- config/langs.php.orig	2007-06-14 19:00:15 UTC
+++ config/langs.php
@@ -47,7 +47,8 @@ $languages = array (
 	'cs'	=> array('cs([-_][[:alpha:]]{2})?|czech', 'cs.lang.php', 'cs', '&#268;esky'),
 	'fr'	=> array('fr([-_][[:alpha:]]{2})?|french', 'fr.lang.php', 'fr', 'Fran&ccedil;ais'),
 	'it'	=> array('it([-_][[:alpha:]]{2})?|italian', 'it.lang.php', 'it', 'Italiano'),
-        'pt_BR' => array('pt([-_]br)?|portuguese', 'pt_BR.lang.php', 'pt', 'Portuguese Brazilian')
+        'pt_BR' => array('pt([-_]br)?|portuguese', 'pt_BR.lang.php', 'pt', 'Portuguese Brazilian'),
+	'pl'   => array('cs([-_][[:alpha:]]{2})?|polish', 'pl.lang.php', 'pl', 'Polski')
 );
 
 // Language files directory	
@@ -113,7 +114,7 @@ function get_browser_lang() {
 	global $languages;
 		
 	if (isset($_SERVER['HTTP_ACCEPT_LANGUAGE']) && !empty($_SERVER['HTTP_ACCEPT_LANGUAGE'])) {
-		$http_accepted = split(',',$_SERVER['HTTP_ACCEPT_LANGUAGE']);
+		$http_accepted = str_split(',',$_SERVER['HTTP_ACCEPT_LANGUAGE']);
 		for ($i = 0; $i < count($http_accepted); $i++) {
 			foreach ($languages as $lang => $vals) {
 				if (eregi($vals[0], $http_accepted[$i]))
