--- ./functions/imap_search.php.orig	2009-11-09 11:29:39.000000000 -0500
+++ ./functions/imap_search.php	2009-11-09 11:38:35.000000000 -0500
@@ -46,22 +46,23 @@
        on the client side, but should be fixed on the server
        as per the RFC */
 
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
+
+    $search_lit = array();
+
+    if ($imap_server_type == 'macosx' || $imap_server_type == 'hmailserver') {
+        $search_string .= $search_where . ' ' . implode(' ', $multi_search);
+    }
     else {
-        foreach ($multi_search as $multi_search_part) {
-            if (strtoupper($languages[$squirrelmail_language]['CHARSET']) == 'ISO-2022-JP') {
-                $multi_search_part = mb_convert_encoding($multi_search_part, 'JIS', 'auto');
-            }
-            $search_string .= $search_where . ' {' . strlen($multi_search_part)
-                . "}\r\n" . $multi_search_part . ' ';
-        }
+        $search_string .= $search_where;
+        $search_lit = array(
+                    'command' => '',
+                    'literal_args' => $multi_search
+                );
     }
 
     $search_string = trim($search_string);
@@ -76,15 +77,24 @@
         $ss = "SEARCH ALL $search_string";
     }
 
-    /* read data back from IMAP */
-    $readin = sqimap_run_command($imapConnection, $ss, false, $result, $message, $uid_support);
+    if (empty($search_lit)) {
+        /* read data back from IMAP */
+        $readin = sqimap_run_command($imapConnection, $ss, false, $result, $message, $uid_support);
+    } else {
+        $search_lit['command'] = $ss;
+        $readin = sqimap_run_literal_command($imapConnection, $search_lit, false, $result, $message, $uid_support);
+    }
 
     /* try US-ASCII charset if search fails */
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
