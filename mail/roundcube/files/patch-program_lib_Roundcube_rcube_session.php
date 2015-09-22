--- program/lib/Roundcube/rcube_session.php.orig	2015-09-22 15:24:26.400132239 +0000
+++ program/lib/Roundcube/rcube_session.php	2015-09-22 15:24:08.430133455 +0000
@@ -35,7 +35,6 @@
     private $time_diff = 0;
     private $reloaded = false;
     private $appends = array();
-    private $unsets = array();
     private $gc_handlers = array();
     private $cookiename = 'roundcube_sessauth';
     private $vars;
@@ -46,6 +45,7 @@
     private $logging = false;
     private $storage;
     private $memcache;
+    private $need_base64 = false;
 
     /**
      * Blocks session data from being written to database.
@@ -95,6 +95,9 @@
         else if ($this->storage != 'php') {
             ini_set('session.serialize_handler', 'php');
 
+            if (ini_get("suhosin.session.encrypt") !== "1")
+                $this->need_base64 = true;
+
             // set custom functions for PHP session management
             session_set_save_handler(
                 array($this, 'open'),
@@ -192,7 +195,7 @@
             $this->time_diff = time() - strtotime($sql_arr['ts']);
             $this->changed   = strtotime($sql_arr['changed']);
             $this->ip        = $sql_arr['ip'];
-            $this->vars      = base64_decode($sql_arr['vars']);
+            $this->vars      = $this->_decode($sql_arr['vars']);
             $this->key       = $key;
 
             return !empty($this->vars) ? (string) $this->vars : '';
@@ -232,12 +235,12 @@
         }
 
         if ($oldvars !== null) {
-            $newvars = $this->_fixvars($vars, $oldvars);
+            $newvars = $vars;
 
             if ($newvars !== $oldvars) {
                 $this->db->query("UPDATE {$this->table_name} "
                     . "SET `changed` = $now, `vars` = ? WHERE `sess_id` = ?",
-                    base64_encode($newvars), $key);
+                    $this->_encode($newvars), $key);
             }
             else if ($ts - $this->changed + $this->time_diff > $this->lifetime / 2) {
                 $this->db->query("UPDATE {$this->table_name} SET `changed` = $now"
@@ -248,44 +251,30 @@
             $this->db->query("INSERT INTO {$this->table_name}"
                 . " (`sess_id`, `vars`, `ip`, `created`, `changed`)"
                 . " VALUES (?, ?, ?, $now, $now)",
-                $key, base64_encode($vars), (string)$this->ip);
+                $key, $this->_encode($vars), (string)$this->ip);
         }
 
         return true;
     }
 
 
-    /**
-     * Merge vars with old vars and apply unsets
-     */
-    private function _fixvars($vars, $oldvars)
+    private function _encode($vars)
     {
-        if ($oldvars !== null) {
-            $a_oldvars = $this->unserialize($oldvars);
-            if (is_array($a_oldvars)) {
-                // remove unset keys on oldvars
-                foreach ((array)$this->unsets as $var) {
-                    if (isset($a_oldvars[$var])) {
-                        unset($a_oldvars[$var]);
-                    }
-                    else {
-                        $path = explode('.', $var);
-                        $k = array_pop($path);
-                        $node = &$this->get_node($path, $a_oldvars);
-                        unset($node[$k]);
-                    }
-                }
-
-                $newvars = $this->serialize(array_merge(
-                    (array)$a_oldvars, (array)$this->unserialize($vars)));
-            }
-            else {
-                $newvars = $vars;
-            }
+        if ($this->need_base64) {
+            return base64_encode($vars);
+        } else {
+            return $vars;
         }
+    }
 
-        $this->unsets = array();
-        return $newvars;
+
+    private function _decode($vars) 
+    {
+        if ($this->need_base64) {
+            return base64_decode($vars);
+        } else {
+            return $vars;
+        }
     }
 
 
@@ -350,7 +339,7 @@
         else // else read data again
             $oldvars = $this->mc_read($key);
 
-        $newvars = $oldvars !== null ? $this->_fixvars($vars, $oldvars) : $vars;
+        $newvars = $vars;
 
         if ($newvars !== $oldvars || $ts - $this->changed > $this->lifetime / 3) {
             return $this->memcache->set($key, serialize(array('changed' => time(), 'ip' => $this->ip, 'vars' => $newvars)),
@@ -488,8 +477,6 @@
             return $this->destroy(session_id());
         }
 
-        $this->unsets[] = $var;
-
         if (isset($_SESSION[$var])) {
             unset($_SESSION[$var]);
         }
