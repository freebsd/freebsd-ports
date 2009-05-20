--- ./functions/i18n.php.orig	2009-05-07 17:55:44.000000000 -0400
+++ ./functions/i18n.php	2009-05-19 23:27:43.000000000 -0400
@@ -640,7 +640,8 @@
             $useragent = func_get_arg(2);
             if (strstr($useragent, 'Windows') !== false ||
                 strstr($useragent, 'Mac_') !== false) {
-                $ret = mb_convert_encoding($ret, 'SJIS', 'AUTO');
+                // $ret = mb_convert_encoding($ret, 'SJIS', 'AUTO'); // for Windows 9x clients
+		$ret = mb_convert_encoding($ret, 'UTF-8', 'AUTO'); // for Windows XP/Vista clients
             } else {
                 $ret = mb_convert_encoding($ret, 'EUC-JP', 'AUTO');
 }
