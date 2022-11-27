--- lib/common.php.orig	2021-12-12 02:35:51 UTC
+++ lib/common.php
@@ -247,9 +247,9 @@ if ($app['language'] == 'auto') {
 
 			$value = preg_split('/[-]+/',$value);
 			if (sizeof($value) == 2)
-				$app['lang_http'][$key] = strtolower($value[0]).'_'.strtoupper($value[1]);
+				$app['lang_http'][$key] = strtolower((string) $value[0]).'_'.strtoupper($value[1]);
 			else
-				$app['lang_http'][$key] = auto_lang(strtolower($value[0]));
+				$app['lang_http'][$key] = auto_lang(strtolower((string) $value[0]));
 		}
 
 		$app['lang_http'] = array_unique($app['lang_http']);
