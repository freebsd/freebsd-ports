--- plugins/AdminTools/include/MultiView.class.php.orig	2018-07-13 13:24:00 UTC
+++ plugins/AdminTools/include/MultiView.class.php
@@ -38,7 +38,7 @@ class MultiView
       );
 
     $this->data_url_params = array_keys($this->data);
-    $this->data_url_params = array_map(create_function('$d', 'return "ato_".$d;'), $this->data_url_params);
+    $this->data_url_params = array_map(function($d) { return 'ato_'.$d; }, $this->data_url_params);
   }
 
   /**
@@ -226,7 +226,7 @@ class MultiView
       }
       if ($this->data['no_history'])
       {
-        $ret_false = create_function('', 'return false;');
+        $ret_false = function() {return false;};
         add_event_handler('pwg_log_allowed', $ret_false);
         add_event_handler('pwg_log_update_last_visit', $ret_false);
       }
