--- program/lib/Roundcube/rcube_session.php.orig	2013-04-15 22:42:22.000000000 +0200
+++ program/lib/Roundcube/rcube_session.php	2013-05-07 12:49:19.000000000 +0200
@@ -33,7 +33,6 @@
     private $start;
     private $changed;
     private $reloaded = false;
-    private $unsets = array();
     private $gc_handlers = array();
     private $cookiename = 'roundcube_sessauth';
     private $vars;
@@ -131,7 +130,7 @@
         if ($sql_result && ($sql_arr = $this->db->fetch_assoc($sql_result))) {
             $this->changed = strtotime($sql_arr['changed']);
             $this->ip      = $sql_arr['ip'];
-            $this->vars    = base64_decode($sql_arr['vars']);
+            $this->vars    = $sql_arr['vars'];
             $this->key     = $key;
 
             return !empty($this->vars) ? (string) $this->vars : '';
@@ -168,13 +167,13 @@
         }
 
         if ($oldvars !== null) {
-            $newvars = $this->_fixvars($vars, $oldvars);
+            $newvars = $vars;
 
             if ($newvars !== $oldvars) {
                 $this->db->query(
                     sprintf("UPDATE %s SET vars=?, changed=%s WHERE sess_id=?",
                         $this->db->table_name('session'), $now),
-                        base64_encode($newvars), $key);
+                        $newvars, $key);
             }
             else if ($ts - $this->changed > $this->lifetime / 2) {
                 $this->db->query("UPDATE ".$this->db->table_name('session')
@@ -186,7 +185,7 @@
                 sprintf("INSERT INTO %s (sess_id, vars, ip, created, changed) ".
                     "VALUES (?, ?, ?, %s, %s)",
                     $this->db->table_name('session'), $now, $now),
-                    $key, base64_encode($vars), (string)$this->ip);
+                    $key, $vars, (string)$this->ip);
         }
 
         return true;
@@ -194,40 +193,6 @@
 
 
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
-                    if (isset($a_oldvars[$k])) {
-                        unset($a_oldvars[$k]);
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
@@ -308,7 +273,7 @@
         else // else read data again
             $oldvars = $this->mc_read($key);
 
-        $newvars = $oldvars !== null ? $this->_fixvars($vars, $oldvars) : $vars;
+        $newvars = $vars;
 
         if ($newvars !== $oldvars || $ts - $this->changed > $this->lifetime / 2) {
             return $this->memcache->set($key, serialize(array('changed' => time(), 'ip' => $this->ip, 'vars' => $newvars)),
@@ -416,8 +381,6 @@
             return $this->destroy(session_id());
         }
 
-        $this->unsets[] = $var;
-
         if (isset($_SESSION[$var])) {
             unset($_SESSION[$var]);
         }
