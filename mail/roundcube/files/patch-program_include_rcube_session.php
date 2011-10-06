--- program/include/rcube_session.php.orig	2011-09-21 14:22:40.000000000 +0200
+++ program/include/rcube_session.php	2011-10-04 18:06:20.000000000 +0200
@@ -33,7 +33,6 @@
   private $ip;
   private $start;
   private $changed;
-  private $unsets = array();
   private $gc_handlers = array();
   private $cookiename = 'roundcube_sessauth';
   private $vars = false;
@@ -132,7 +131,7 @@
     if ($sql_result && ($sql_arr = $this->db->fetch_assoc($sql_result))) {
       $this->changed = strtotime($sql_arr['changed']);
       $this->ip      = $sql_arr['ip'];
-      $this->vars    = base64_decode($sql_arr['vars']);
+      $this->vars    = $sql_arr['vars'];
       $this->key     = $key;
 
       if (!empty($this->vars))
@@ -169,15 +168,7 @@
     }
 
     if ($oldvars !== false) {
-      $newvars = $this->_fixvars($vars, $oldvars);
-
-      if ($newvars !== $oldvars) {
-        $this->db->query(
-          sprintf("UPDATE %s SET vars=?, changed=%s WHERE sess_id=?",
-            get_table_name('session'), $now),
-          base64_encode($newvars), $key);
-      }
-      else if ($ts - $this->changed > $this->lifetime / 2) {
+      if ($ts - $this->changed > $this->lifetime / 2) {
         $this->db->query("UPDATE ".get_table_name('session')." SET changed=$now WHERE sess_id=?", $key);
       }
     }
@@ -186,7 +177,7 @@
         sprintf("INSERT INTO %s (sess_id, vars, ip, created, changed) ".
           "VALUES (?, ?, ?, %s, %s)",
           get_table_name('session'), $now, $now),
-        $key, base64_encode($vars), (string)$this->ip);
+        $key, $vars, (string)$this->ip);
     }
 
     return true;
@@ -194,29 +185,6 @@
 
 
   /**
-   * Merge vars with old vars and apply unsets
-   */
-  private function _fixvars($vars, $oldvars)
-  {
-    if ($oldvars !== false) {
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
-    }
-
-    $this->unsets = array();
-    return $newvars;
-  }
-
-
-  /**
    * Handler for session_destroy()
    *
    * @param string Session ID
@@ -295,7 +263,7 @@
     else // else read data again
       $oldvars = $this->mc_read($key);
 
-    $newvars = $oldvars !== false ? $this->_fixvars($vars, $oldvars) : $vars;
+    $newvars = $oldvars !== false ? $oldvars : $vars;
     
     if ($newvars !== $oldvars || $ts - $this->changed > $this->lifetime / 2) {
       $value = serialize(array('changed' => time(), 'ip' => $this->ip, 'vars' => $newvars));
@@ -386,7 +354,6 @@
     if (empty($var))
       return $this->destroy(session_id());
 
-    $this->unsets[] = $var;
     unset($_SESSION[$var]);
 
     return true;
