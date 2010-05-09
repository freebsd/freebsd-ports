--- ./includes/base_state_citems.inc.php.orig	2010-03-05 16:06:18.000000000 +0100
+++ ./includes/base_state_citems.inc.php	2010-04-11 23:52:13.000000000 +0200
@@ -963,7 +963,7 @@
       for ( $i = 0; $i < $this->criteria_cnt; $i++ )
       {
         if ( (isset ($this->criteria[$i][3])) &&
-             (ereg("([0-9]*)\.([0-9]*)\.([0-9]*)\.([0-9]*)", $this->criteria[$i][3])) )
+             (preg_match("/([0-9]*)\.([0-9]*)\.([0-9]*)\.([0-9]*)/", $this->criteria[$i][3])) )
         {
            $tmp_ip_str = $this->criteria[$i][7] = $this->criteria[$i][3];
            $this->criteria[$i][3] = strtok($tmp_ip_str, ".");
