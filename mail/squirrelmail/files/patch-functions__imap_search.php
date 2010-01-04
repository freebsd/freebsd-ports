--- functions/imap_search.php	2009/07/29 02:21:06	13800
+++ functions/imap_search.php	2009/12/14 21:18:29	13877
@@ -5,7 +5,7 @@
  *
  * IMAP search routines
  *
- * @copyright &copy; 1999-2009 The SquirrelMail Project Team
+ * @copyright 1999-2009 The SquirrelMail Project Team
  * @license http://opensource.org/licenses/gpl-license.php GNU Public License
  * @version $Id$
  * @package squirrelmail
@@ -38,30 +38,17 @@
     $multi_search = explode(' ', $search_what);
     $search_string = '';
 
-    /* it seems macosx and hmailserver do not support the prefered search
-       syntax so we fall back to the older style. This IMAP
-       server has a problem with multiple search terms. Instead
-       of returning the messages that match all the terms it
-       returns the messages that match each term. Could be fixed
-       on the client side, but should be fixed on the server
-       as per the RFC */
-
-    if ($imap_server_type == 'macosx' || $imap_server_type == 'hmailserver') {
-        foreach ($multi_search as $multi_search_part) {
-            if (strtoupper($languages[$squirrelmail_language]['CHARSET']) == 'ISO-2022-JP') {
-                $multi_search_part = mb_convert_encoding($multi_search_part, 'JIS', 'auto');
-            }
-            $search_string .= $search_where . ' ' .$multi_search_part . ' ';
+    if (strtoupper($languages[$squirrelmail_language]['CHARSET'] == 'ISO-2022-JP')) {
+        foreach($multi_search as $idx=>$search_part) {
+            $multi_search[$idx] = mb_convert_encoding($search_parth, 'JIS', 'auto');
         }
     }
-    else {
-        foreach ($multi_search as $multi_search_part) {
-            if (strtoupper($languages[$squirrelmail_language]['CHARSET']) == 'ISO-2022-JP') {
-                $multi_search_part = mb_convert_encoding($multi_search_part, 'JIS', 'auto');
-            }
-            $search_string .= $search_where . ' {' . strlen($multi_search_part)
-                . "}\r\n" . $multi_search_part . ' ';
-        }
+
+    foreach ($multi_search as $string) {
+       $search_string .= $search_where
+                      . ' "'
+                      . str_replace(array('\\', '"'), array('\\\\', '\\"'), $string)
+                      . '" ';
     }
 
     $search_string = trim($search_string);
@@ -83,8 +70,12 @@
     if (isset($languages[$squirrelmail_language]['CHARSET'])
         && strtolower($result) == 'no') {
         $ss = "SEARCH CHARSET \"US-ASCII\" ALL $search_string";
-        $readin = sqimap_run_command ($imapConnection, $ss, true,
-                                      $result, $message, $uid_support);
+        if (empty($search_lit)) {
+            $readin = sqimap_run_command($imapConnection, $ss, false, $result, $message, $uid_support);
+        } else {
+            $search_lit['command'] = $ss;
+            $readin = sqimap_run_literal_command($imapConnection, $search_lit, false, $result, $message, $uid_support);
+        }
     }
 
     unset($messagelist);
