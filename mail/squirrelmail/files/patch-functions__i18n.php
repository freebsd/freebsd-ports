--- functions/i18n.php.orig	2015-01-03 03:56:32 UTC
+++ functions/i18n.php
@@ -683,7 +683,8 @@ function japanese_charset_xtra() {
             $useragent = func_get_arg(2);
             if (strstr($useragent, 'Windows') !== false ||
                 strstr($useragent, 'Mac_') !== false) {
-                $ret = mb_convert_encoding($ret, 'SJIS', 'AUTO');
+                $ret = mb_convert_encoding($ret, 'UTF-8', 'AUTO');
+
             } else {
                 $ret = mb_convert_encoding($ret, 'EUC-JP', 'AUTO');
 }
