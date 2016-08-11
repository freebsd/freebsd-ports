--- program/lib/Roundcube/rcube_session_db.php.orig	2016-05-22 11:06:47 UTC
+++ program/lib/Roundcube/rcube_session_db.php
@@ -32,6 +32,7 @@ class rcube_session_db extends rcube_ses
 {
     private $db;
     private $table_name;
+    private $need_base64;
 
     /**
      * @param Object $config
@@ -39,6 +40,9 @@ class rcube_session_db extends rcube_ses
     public function __construct($config)
     {
         parent::__construct($config);
+        
+        // base64 encode if suhosin is not enabled
+        $this->need_base64 = ini_get("suhosin.session.encrypt") !== "1";
 
         // get db instance
         $this->db = rcube::get_instance()->get_dbh();
@@ -103,7 +107,7 @@ class rcube_session_db extends rcube_ses
             $this->time_diff = time() - strtotime($sql_arr['ts']);
             $this->changed   = strtotime($sql_arr['changed']);
             $this->ip        = $sql_arr['ip'];
-            $this->vars      = base64_decode($sql_arr['vars']);
+            $this->vars      = $this->_decode($sql_arr['vars']);
             $this->key       = $key;
 
             return !empty($this->vars) ? (string) $this->vars : '';
@@ -126,7 +130,7 @@ class rcube_session_db extends rcube_ses
         $this->db->query("INSERT INTO {$this->table_name}"
             . " (`sess_id`, `vars`, `ip`, `created`, `changed`)"
             . " VALUES (?, ?, ?, $now, $now)",
-            $key, base64_encode($vars), (string)$this->ip);
+            $key, $this->_encode($vars), (string)$this->ip);
 
         return true;
     }
@@ -150,7 +154,7 @@ class rcube_session_db extends rcube_ses
         if ($newvars !== $oldvars) {
             $this->db->query("UPDATE {$this->table_name} "
                 . "SET `changed` = $now, `vars` = ? WHERE `sess_id` = ?",
-                base64_encode($newvars), $key);
+                $this->_encode($newvars), $key);
         }
         else if ($ts - $this->changed + $this->time_diff > $this->lifetime / 2) {
             $this->db->query("UPDATE {$this->table_name} SET `changed` = $now"
@@ -173,4 +177,23 @@ class rcube_session_db extends rcube_ses
             . date('Y-m-d H:i:s', time() - $this->gc_enabled)
             . '; rows = ' . intval($this->db->affected_rows()));
     }
+
+    private function _encode($vars)
+    {
+        if ($this->need_base64) {
+            return base64_encode($vars);
+        } else {
+            return $vars;
+        }
+    }
+
+    private function _decode($vars) 
+    {
+        if ($this->need_base64) {
+            return base64_decode($vars);
+        } else {
+            return $vars;
+        }
+    }
+
 }
