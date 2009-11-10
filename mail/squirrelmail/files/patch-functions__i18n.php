--- ./functions/i18n.php.orig	2009-07-28 22:21:06.000000000 -0400
+++ ./functions/i18n.php	2009-11-09 11:22:46.000000000 -0500
@@ -675,7 +675,7 @@
             break;
         case 'decodeheader':
             $ret = str_replace("\t", "", $ret);
-            if (preg_match('/=\?([^?]+)\?(q|b)\?([^?]+)\?=/', $ret))
+            if (preg_match('/=\?([^?]+)\?(q|b)\?([^?]+)\?=/i', $ret))
                 $ret = @mb_decode_mimeheader($ret);
             $ret = @mb_convert_encoding($ret, 'EUC-JP', 'AUTO');
             break;
@@ -683,7 +683,8 @@
             $useragent = func_get_arg(2);
             if (strstr($useragent, 'Windows') !== false ||
                 strstr($useragent, 'Mac_') !== false) {
-                $ret = mb_convert_encoding($ret, 'SJIS', 'AUTO');
+                // $ret = mb_convert_encoding($ret, 'SJIS', 'AUTO'); // for Windows 9x clients
+		$ret = mb_convert_encoding($ret, 'UTF-8', 'AUTO'); // for Windows XP/Vista clients
             } else {
                 $ret = mb_convert_encoding($ret, 'EUC-JP', 'AUTO');
 }
