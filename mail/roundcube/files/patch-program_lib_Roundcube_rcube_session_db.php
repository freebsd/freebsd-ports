--- program/lib/Roundcube/rcube_session_db.php.orig	2017-06-26 20:56:48.000000000 +0200
+++ program/lib/Roundcube/rcube_session_db.php	2017-06-30 10:21:12.859240000 +0200
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
 
             $this->db->reset();
@@ -128,7 +132,7 @@ class rcube_session_db extends rcube_ses
         $this->db->query("INSERT INTO {$this->table_name}"
             . " (`sess_id`, `vars`, `ip`, `changed`)"
             . " VALUES (?, ?, ?, $now)",
-            $key, base64_encode($vars), (string)$this->ip);
+            $key, $this->_encode($vars), (string)$this->ip);
 
         return true;
     }
@@ -152,7 +156,7 @@ class rcube_session_db extends rcube_ses
         if ($newvars !== $oldvars) {
             $this->db->query("UPDATE {$this->table_name} "
                 . "SET `changed` = $now, `vars` = ? WHERE `sess_id` = ?",
-                base64_encode($newvars), $key);
+                $this->_encode($newvars), $key);
         }
         else if ($ts - $this->changed + $this->time_diff > $this->lifetime / 2) {
             $this->db->query("UPDATE {$this->table_name} SET `changed` = $now"
@@ -175,4 +179,23 @@ class rcube_session_db extends rcube_ses
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
