--- program/include/rcube_session.php.orig	2010-11-27 14:59:05.000000000 +0100
+++ program/include/rcube_session.php	2010-12-13 17:50:47.000000000 +0100
@@ -32,7 +32,6 @@
   private $db;
   private $ip;
   private $changed;
-  private $unsets = array();
   private $gc_handlers = array();
   private $start;
   private $vars = false;
@@ -82,7 +81,7 @@
     if ($sql_arr = $this->db->fetch_assoc($sql_result)) {
       $this->changed = $sql_arr['changed'];
       $this->ip      = $sql_arr['ip'];
-      $this->vars    = base64_decode($sql_arr['vars']);
+      $this->vars    = $sql_arr['vars'];
       $this->key     = $key;
 
       if (!empty($this->vars))
@@ -107,17 +106,6 @@
     }
 
     if ($oldvars !== false) {
-      $a_oldvars = $this->unserialize($oldvars);
-      if (is_array($a_oldvars)) {
-        foreach ((array)$this->unsets as $k)
-          unset($a_oldvars[$k]);
-
-        $newvars = $this->serialize(array_merge(
-          (array)$a_oldvars, (array)$this->unserialize($vars)));
-      }
-      else
-        $newvars = $vars;
-
       if (!$this->lifetime) {
         $timeout = 600;
       }
@@ -127,11 +115,11 @@
         $timeout = 0;
       }
 
-      if (!($newvars === $oldvars) || ($ts - $this->changed > $timeout)) {
+      if (!($vars === $oldvars) || ($ts - $this->changed > $timeout)) {
         $this->db->query(
           sprintf("UPDATE %s SET vars = ?, changed = %s WHERE sess_id = ?",
             get_table_name('session'), $now),
-          base64_encode($newvars), $key);
+          $vars, $key);
       }
     }
     else {
@@ -139,10 +127,9 @@
         sprintf("INSERT INTO %s (sess_id, vars, ip, created, changed) ".
           "VALUES (?, ?, ?, %s, %s)",
           get_table_name('session'), $now, $now),
-        $key, base64_encode($vars), (string)$_SERVER['REMOTE_ADDR']);
+        $key, $vars, (string)$_SERVER['REMOTE_ADDR']);
     }
 
-    $this->unsets = array();
     return true;
   }
 
@@ -212,112 +199,12 @@
     if (empty($var))
       return $this->destroy(session_id());
 
-    $this->unsets[] = $var;
     unset($_SESSION[$var]);
 
     return true;
   }
 
 
-  // serialize session data
-  private function serialize($vars)
-  {
-    $data = '';
-    if (is_array($vars))
-      foreach ($vars as $var=>$value)
-        $data .= $var.'|'.serialize($value);
-    else
-      $data = 'b:0;';
-    return $data;
-  }
-
-
-  // unserialize session data
-  // http://www.php.net/manual/en/function.session-decode.php#56106
-  private function unserialize($str)
-  {
-    $str = (string)$str;
-    $endptr = strlen($str);
-    $p = 0;
-
-    $serialized = '';
-    $items = 0;
-    $level = 0;
-
-    while ($p < $endptr) {
-      $q = $p;
-      while ($str[$q] != '|')
-        if (++$q >= $endptr) break 2;
-
-      if ($str[$p] == '!') {
-        $p++;
-        $has_value = false;
-      } else {
-        $has_value = true;
-      }
-
-      $name = substr($str, $p, $q - $p);
-      $q++;
-
-      $serialized .= 's:' . strlen($name) . ':"' . $name . '";';
-
-      if ($has_value) {
-        for (;;) {
-          $p = $q;
-          switch (strtolower($str[$q])) {
-            case 'n': /* null */
-            case 'b': /* boolean */
-            case 'i': /* integer */
-            case 'd': /* decimal */
-              do $q++;
-              while ( ($q < $endptr) && ($str[$q] != ';') );
-              $q++;
-              $serialized .= substr($str, $p, $q - $p);
-              if ($level == 0) break 2;
-              break;
-            case 'r': /* reference  */
-              $q+= 2;
-              for ($id = ''; ($q < $endptr) && ($str[$q] != ';'); $q++) $id .= $str[$q];
-              $q++;
-              $serialized .= 'R:' . ($id + 1) . ';'; /* increment pointer because of outer array */
-              if ($level == 0) break 2;
-              break;
-            case 's': /* string */
-              $q+=2;
-              for ($length=''; ($q < $endptr) && ($str[$q] != ':'); $q++) $length .= $str[$q];
-              $q+=2;
-              $q+= (int)$length + 2;
-              $serialized .= substr($str, $p, $q - $p);
-              if ($level == 0) break 2;
-              break;
-            case 'a': /* array */
-            case 'o': /* object */
-              do $q++;
-              while ( ($q < $endptr) && ($str[$q] != '{') );
-              $q++;
-              $level++;
-              $serialized .= substr($str, $p, $q - $p);
-              break;
-            case '}': /* end of array|object */
-              $q++;
-              $serialized .= substr($str, $p, $q - $p);
-              if (--$level == 0) break 2;
-              break;
-            default:
-              return false;
-          }
-        }
-      } else {
-        $serialized .= 'N;';
-        $q += 2;
-      }
-      $items++;
-      $p = $q;
-    }
-
-    return unserialize( 'a:' . $items . ':{' . $serialized . '}' );
-  }
-
   public function set_keep_alive($keep_alive)
   {
     $this->keep_alive = $keep_alive;
