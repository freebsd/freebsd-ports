--- program/lib/Roundcube/rcube_session.php.orig	2015-02-08 13:43:28.000000000 +0000
+++ program/lib/Roundcube/rcube_session.php	2015-02-19 13:43:29.477065794 +0000
@@ -35,7 +35,6 @@
     private $time_diff = 0;
     private $reloaded = false;
     private $appends = array();
-    private $unsets = array();
     private $gc_handlers = array();
     private $cookiename = 'roundcube_sessauth';
     private $vars;
@@ -184,7 +183,7 @@
             $this->time_diff = time() - strtotime($sql_arr['ts']);
             $this->changed   = strtotime($sql_arr['changed']);
             $this->ip        = $sql_arr['ip'];
-            $this->vars      = base64_decode($sql_arr['vars']);
+            $this->vars      = $sql_arr['vars'];
             $this->key       = $key;
 
             return !empty($this->vars) ? (string) $this->vars : '';
@@ -224,12 +223,12 @@
         }
 
         if ($oldvars !== null) {
-            $newvars = $this->_fixvars($vars, $oldvars);
+            $newvars = $vars;
 
             if ($newvars !== $oldvars) {
                 $this->db->query("UPDATE {$this->table_name} "
                     . "SET `changed` = $now, `vars` = ? WHERE `sess_id` = ?",
-                    base64_encode($newvars), $key);
+                    $newvars, $key);
             }
             else if ($ts - $this->changed + $this->time_diff > $this->lifetime / 2) {
                 $this->db->query("UPDATE {$this->table_name} SET `changed` = $now"
@@ -240,7 +239,7 @@
             $this->db->query("INSERT INTO {$this->table_name}"
                 . " (`sess_id`, `vars`, `ip`, `created`, `changed`)"
                 . " VALUES (?, ?, ?, $now, $now)",
-                $key, base64_encode($vars), (string)$this->ip);
+                $key, $vars, (string)$this->ip);
         }
 
         return true;
@@ -248,40 +247,6 @@
 
 
     /**
-     * Merge vars with old vars and apply unsets
-     */
-    private function _fixvars($vars, $oldvars)
-    {
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
-        }
-
-        $this->unsets = array();
-        return $newvars;
-    }
-
-
-    /**
      * Handler for session_destroy()
      *
      * @param string Session ID
@@ -342,7 +307,7 @@
         else // else read data again
             $oldvars = $this->mc_read($key);
 
-        $newvars = $oldvars !== null ? $this->_fixvars($vars, $oldvars) : $vars;
+        $newvars = $vars;
 
         if ($newvars !== $oldvars || $ts - $this->changed > $this->lifetime / 3) {
             return $this->memcache->set($key, serialize(array('changed' => time(), 'ip' => $this->ip, 'vars' => $newvars)),
@@ -480,8 +445,6 @@
             return $this->destroy(session_id());
         }
 
-        $this->unsets[] = $var;
-
         if (isset($_SESSION[$var])) {
             unset($_SESSION[$var]);
         }
