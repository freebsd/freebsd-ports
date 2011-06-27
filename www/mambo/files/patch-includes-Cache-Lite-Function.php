--- includes/Cache/Lite/Function.php.old        2011-06-27 09:54:53.000000000 +1000
+++ includes/Cache/Lite/Function.php    2011-06-27 09:56:11.000000000 +1000
@@ -72,6 +72,13 @@
     function call()
     {
         $arguments = func_get_args();
+
+       $numargs = func_num_args();
+
+       for($i=1; $i < $numargs; $i++) {
+               $arguments[$i] = &$arguments[$i];
+       }
+
         $id = serialize($arguments); // Generate a cache id
         if (!$this->_fileNameProtection) {
             $id = md5($id);

