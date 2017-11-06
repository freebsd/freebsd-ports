--- functions/strings.php.orig	2017-01-27 20:31:33 UTC
+++ functions/strings.php
@@ -1489,7 +1489,13 @@ function sm_validate_security_token($tok
   *                   (See http://php.net/manual/function.htmlspecialchars.php )
   *                   (OPTIONAL; default ENT_COMPAT, ENT_COMPAT | ENT_SUBSTITUTE for PHP >=5.4)
   * @param string $encoding The character encoding to use in the conversion
-  *                         (OPTIONAL; default automatic detection)
+  *                         (if not one of the character sets supported
+  *                         by PHP's htmlspecialchars(), then $encoding
+  *                         will be ignored and iso-8859-1 will be used,
+  *                         unless a default has been specified in
+  *                         $default_htmlspecialchars_encoding in
+  *                         config_local.php) (OPTIONAL; default automatic
+  *                         detection)
   * @param boolean $double_encode Whether or not to convert entities that are
   *                               already in the string (only supported in
   *                               PHP 5.2.3+) (OPTIONAL; default TRUE)
@@ -1500,6 +1506,31 @@ function sm_validate_security_token($tok
 function sm_encode_html_special_chars($string, $flags=ENT_COMPAT,
                                       $encoding=NULL, $double_encode=TRUE)
 {
+
+   // charsets supported by PHP's htmlspecialchars
+   // (move this elsewhere if needed)
+   //
+   static $htmlspecialchars_charsets = array(
+      'iso-8859-1', 'iso8859-1',
+      'iso-8859-5', 'iso8859-5',
+      'iso-8859-15', 'iso8859-15',
+      'utf-8',
+      'cp866', 'ibm866', '866',
+      'cp1251', 'windows-1251', 'win-1251', '1251',
+      'cp1252', 'windows-1252', '1252',
+      'koi8-R', 'koi8-ru', 'koi8r',
+      'big5', '950',
+      'gb2312', '936',
+      'big5-hkscs',
+      'shift_jis', 'sjis', 'sjis-win', 'cp932', '932',
+      'euc-jp', 'eucjp', 'eucjp-win',
+      'macroman',
+   );
+
+
+   // if not given, set encoding to the charset being
+   // used by the current user interface language
+   //
    if (!$encoding)
    {
       global $default_charset;
@@ -1508,6 +1539,21 @@ function sm_encode_html_special_chars($s
       $encoding = $default_charset;
    }
 
+
+   // make sure htmlspecialchars() supports the needed encoding
+   //
+   if (!in_array(strtolower($encoding), $htmlspecialchars_charsets))
+   {
+      // use default from configuration if provided or hard-coded fallback
+      //
+      global $default_htmlspecialchars_encoding;
+      if (!empty($default_htmlspecialchars_encoding))
+         $encoding = $default_htmlspecialchars_encoding;
+      else
+         $encoding = 'iso-8859-1';
+   }
+
+
    if (check_php_version(5, 2, 3)) {
       // Replace invalid characters with a symbol instead of returning
       // empty string for the entire to be encoded string.
