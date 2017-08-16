--- program/lib/Roundcube/rcube_session.php.orig	2017-06-26 20:56:48.000000000 +0200
+++ program/lib/Roundcube/rcube_session.php	2017-06-30 10:20:36.890382000 +0200
@@ -39,7 +39,6 @@ abstract class rcube_session
     protected $time_diff    = 0;
     protected $reloaded     = false;
     protected $appends      = array();
-    protected $unsets       = array();
     protected $gc_enabled   = 0;
     protected $gc_handlers  = array();
     protected $cookiename   = 'roundcube_sessauth';
@@ -158,7 +157,7 @@ abstract class rcube_session
 
         // if there are cached vars, update store, else insert new data
         if ($oldvars) {
-            $newvars = $this->_fixvars($vars, $oldvars);
+            $newvars = $vars;
             return $this->update($key, $newvars, $oldvars);
         }
         else {
@@ -198,39 +197,6 @@ abstract class rcube_session
     }
 
     /**
-     * Merge vars with old vars and apply unsets
-     */
-    protected function _fixvars($vars, $oldvars)
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
-    /**
      * Execute registered garbage collector routines
      */
     public function gc($maxlifetime)
@@ -339,11 +305,6 @@ abstract class rcube_session
         }
 
         $this->appends[] = $path;
-
-        // when overwriting a previously unset variable
-        if ($this->unsets[$path]) {
-            unset($this->unsets[$path]);
-        }
     }
 
     /**
@@ -358,8 +319,6 @@ abstract class rcube_session
             return $this->destroy(session_id());
         }
 
-        $this->unsets[] = $var;
-
         if (isset($_SESSION[$var])) {
             unset($_SESSION[$var]);
         }
@@ -405,21 +364,6 @@ abstract class rcube_session
 
         if ($data) {
             session_decode($data);
-
-            // apply appends and unsets to reloaded data
-            $_SESSION = array_merge_recursive($_SESSION, $merge_data);
-
-            foreach ((array)$this->unsets as $var) {
-                if (isset($_SESSION[$var])) {
-                    unset($_SESSION[$var]);
-                }
-                else {
-                    $path = explode('.', $var);
-                    $k = array_pop($path);
-                    $node = &$this->get_node($path, $_SESSION);
-                    unset($node[$k]);
-                }
-            }
         }
     }
 
