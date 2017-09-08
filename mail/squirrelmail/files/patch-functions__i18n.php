--- functions/i18n.php.orig	2017-07-05 11:28:23 UTC
+++ functions/i18n.php
@@ -159,15 +159,17 @@ function sq_setlocale($category,$locale)
 }
 
 /**
- * Converts string from given charset to charset, that can be displayed by user translation.
+ * Converts a string from the given $charset to a character set that
+ * can be displayed by the current user interface language (translation)
  *
- * Function by default returns html encoded strings, if translation uses different encoding.
+ * Function by default returns html encoded strings if translation uses
+ * different encoding.
  * If Japanese translation is used - function returns string converted to euc-jp
  * If $charset is not supported - function returns unconverted string.
  *
  * sanitizing of html tags is also done by this function.
  *
- * @param string $charset
+ * @param string $charset The charset of the incoming string
  * @param string $string Text to be decoded
  * @param boolean $force_decode converts string to html without $charset!=$default_charset check.
  * Argument is available since 1.4.5 and 1.5.1.
@@ -184,7 +186,7 @@ function charset_decode ($charset, $stri
     }
 
     /* All HTML special characters are 7 bit and can be replaced first */
-    if (! $save_html) $string = sm_encode_html_special_chars ($string);
+    if (! $save_html) $string = sm_encode_html_special_chars($string, ENT_COMPAT, $charset);
     $charset = strtolower($charset);
 
     set_my_charset();
