--- ./functions/i18n.php.orig	2009-07-28 22:21:06.000000000 -0400
+++ ./functions/i18n.php	2009-10-08 10:30:25.000000000 -0400
@@ -146,7 +146,7 @@
     }
 
     /* safety checks */
-    if (preg_match("/^.*\/.*\/.*\/.*\/.*\/.*$/",$ret)) {
+    if (preg_match("/^.*\/.*\/.*\/.*\/.*\/.*$/i",$ret)) {
         /**
          * Welcome to We-Don't-Follow-Own-Fine-Manual department
          * OpenBSD 3.8, 3.9-current and maybe later versions
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
