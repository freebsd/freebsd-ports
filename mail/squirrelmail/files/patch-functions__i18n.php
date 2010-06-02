--- ./functions/i18n.php.orig	2010-06-02 11:26:40.000000000 -0400
+++ ./functions/i18n.php	2010-06-02 11:28:33.000000000 -0400
@@ -683,7 +683,8 @@
             $useragent = func_get_arg(2);
             if (strstr($useragent, 'Windows') !== false ||
                 strstr($useragent, 'Mac_') !== false) {
-                $ret = mb_convert_encoding($ret, 'SJIS', 'AUTO');
+                $ret = mb_convert_encoding($ret, 'UTF-8', 'AUTO');
+
             } else {
                 $ret = mb_convert_encoding($ret, 'EUC-JP', 'AUTO');
 }
