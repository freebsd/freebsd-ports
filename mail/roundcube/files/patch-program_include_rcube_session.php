--- program/include/rcube_session.php.orig	2012-08-06 18:18:13.000000000 +0200
+++ program/include/rcube_session.php	2012-08-13 12:44:54.000000000 +0200
@@ -37,7 +37,6 @@
   private $ip;
   private $start;
   private $changed;
-  private $unsets = array();
   private $gc_handlers = array();
   private $cookiename = 'roundcube_sessauth';
   private $vars;
@@ -134,7 +133,7 @@
     if ($sql_result && ($sql_arr = $this->db->fetch_assoc($sql_result))) {
       $this->changed = strtotime($sql_arr['changed']);
       $this->ip      = $sql_arr['ip'];
-      $this->vars    = base64_decode($sql_arr['vars']);
+      $this->vars    = $sql_arr['vars'];
       $this->key     = $key;
 
       return !empty($this->vars) ? (string) $this->vars : '';
@@ -170,13 +169,13 @@
     }
 
     if ($oldvars !== null) {
-      $newvars = $this->_fixvars($vars, $oldvars);
+      $newvars = $vars;
 
       if ($newvars !== $oldvars) {
         $this->db->query(
           sprintf("UPDATE %s SET vars=?, changed=%s WHERE sess_id=?",
             get_table_name('session'), $now),
-          base64_encode($newvars), $key);
+          $newvars, $key);
       }
       else if ($ts - $this->changed > $this->lifetime / 2) {
         $this->db->query("UPDATE ".get_table_name('session')." SET changed=$now WHERE sess_id=?", $key);
@@ -187,7 +186,7 @@
         sprintf("INSERT INTO %s (sess_id, vars, ip, created, changed) ".
           "VALUES (?, ?, ?, %s, %s)",
           get_table_name('session'), $now, $now),
-        $key, base64_encode($vars), (string)$this->ip);
+        $key, $vars, (string)$this->ip);
     }
 
     return true;
@@ -195,29 +194,6 @@
 
 
   /**
-   * Merge vars with old vars and apply unsets
-   */
-  private function _fixvars($vars, $oldvars)
-  {
-    if ($oldvars !== null) {
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
@@ -296,7 +272,7 @@
     else // else read data again
       $oldvars = $this->mc_read($key);
 
-    $newvars = $oldvars !== null ? $this->_fixvars($vars, $oldvars) : $vars;
+    $newvars = $vars;
 
     if ($newvars !== $oldvars || $ts - $this->changed > $this->lifetime / 2)
       return $this->memcache->set($key, serialize(array('changed' => time(), 'ip' => $this->ip, 'vars' => $newvars)), MEMCACHE_COMPRESSED, $this->lifetime);
@@ -376,7 +352,6 @@
     if (empty($var))
       return $this->destroy(session_id());
 
-    $this->unsets[] = $var;
     unset($_SESSION[$var]);
 
     return true;
