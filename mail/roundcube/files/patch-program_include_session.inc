--- program/include/session.inc.orig	2009-09-07 22:22:55.000000000 +0200
+++ program/include/session.inc	2009-09-07 22:47:29.000000000 +0200
@@ -19,8 +19,6 @@
 
 */
 
-$GLOBALS['rcube_session_unsets'] = array();
-
 function rcube_sess_open($save_path, $session_name)
 {
   return true;
@@ -66,20 +64,15 @@
   $now = $DB->fromunixtime(time());
 
   $sql_result = $DB->query(
-    "SELECT vars FROM " . get_table_name('session') . "
+    "SELECT 1 FROM " . get_table_name('session') . "
      WHERE  sess_id=?", $key);
 
-  if ($sql_arr = $DB->fetch_assoc($sql_result)) {
-
-    $a_oldvars = rcube_sess_unserialize($sql_arr['vars']);
-    foreach ((array)$GLOBALS['rcube_session_unsets'] as $k)
-      unset($a_oldvars[$k]);
-
+  if ($DB->num_rows($sql_result)) {
     $DB->query(
       "UPDATE " . get_table_name('session') . "
        SET    vars=?, changed= " . $now . "
        WHERE  sess_id=?",
-      rcube_sess_serialize(array_merge($a_oldvars, rcube_sess_unserialize($vars))),
+      $vars,
       $key);
   }
   else {
@@ -92,7 +85,6 @@
       (string)$_SERVER['REMOTE_ADDR']);
   }
 
-  $GLOBALS['rcube_session_unsets'] = array();
   return true;
 }
 
@@ -103,113 +95,12 @@
   if (empty($var))
     return rcube_sess_destroy(session_id());
 
-  $GLOBALS['rcube_session_unsets'][] = $var;
   unset($_SESSION[$var]);
 
   return true;
 }
 
 
-// serialize session data
-function rcube_sess_serialize($vars)
-{
-  $data = '';
-  if (is_array($vars))
-    foreach ($vars as $var=>$value)
-      $data .= $var.'|'.serialize($value);
-  else
-    $data = 'b:0;';
-  return $data;
-}
-
-
-// unserialize session data
-// http://www.php.net/manual/en/function.session-decode.php#56106
-function rcube_sess_unserialize($str)
-{
-  $str = (string)$str;
-  $endptr = strlen($str);
-  $p = 0;
-
-  $serialized = '';
-  $items = 0;
-  $level = 0;
-
-  while ($p < $endptr) {
-    $q = $p;
-    while ($str[$q] != '|')
-      if (++$q >= $endptr) break 2;
-
-    if ($str[$p] == '!') {
-      $p++;
-      $has_value = false;
-    } else {
-      $has_value = true;
-    }
-
-    $name = substr($str, $p, $q - $p);
-    $q++;
-
-    $serialized .= 's:' . strlen($name) . ':"' . $name . '";';
-
-    if ($has_value) {
-      for (;;) {
-        $p = $q;
-        switch (strtolower($str[$q])) {
-          case 'n': /* null */
-          case 'b': /* boolean */
-          case 'i': /* integer */
-          case 'd': /* decimal */
-            do $q++;
-            while ( ($q < $endptr) && ($str[$q] != ';') );
-            $q++;
-            $serialized .= substr($str, $p, $q - $p);
-            if ($level == 0) break 2;
-            break;
-          case 'r': /* reference  */
-            $q+= 2;
-            for ($id = ''; ($q < $endptr) && ($str[$q] != ';'); $q++) $id .= $str[$q];
-            $q++;
-            $serialized .= 'R:' . ($id + 1) . ';'; /* increment pointer because of outer array */
-            if ($level == 0) break 2;
-            break;
-          case 's': /* string */
-            $q+=2;
-            for ($length=''; ($q < $endptr) && ($str[$q] != ':'); $q++) $length .= $str[$q];
-            $q+=2;
-            $q+= (int)$length + 2;
-            $serialized .= substr($str, $p, $q - $p);
-            if ($level == 0) break 2;
-            break;
-          case 'a': /* array */
-          case 'o': /* object */
-            do $q++;
-            while ( ($q < $endptr) && ($str[$q] != '{') );
-            $q++;
-            $level++;
-            $serialized .= substr($str, $p, $q - $p);
-            break;
-          case '}': /* end of array|object */
-            $q++;
-            $serialized .= substr($str, $p, $q - $p);
-            if (--$level == 0) break 2;
-            break;
-          default:
-            return false;
-        }
-      }
-    } else {
-      $serialized .= 'N;';
-      $q+= 2;
-    }
-    $items++;
-    $p = $q;
-  }
-
-  return unserialize( 'a:' . $items . ':{' . $serialized . '}' );
-}
-
-
 // handler for session_destroy()
 function rcube_sess_destroy($key)
 {
