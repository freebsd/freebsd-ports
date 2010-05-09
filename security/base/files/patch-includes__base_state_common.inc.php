--- ./includes/base_state_common.inc.php.orig	2010-03-05 16:06:18.000000000 +0100
+++ ./includes/base_state_common.inc.php	2010-04-11 23:52:13.000000000 +0200
@@ -181,7 +181,7 @@
    if ( ($valid_data & VAR_SCORE) > 0 ) 
       $regex_mask = $regex_mask . "\-";
 
-   return ereg_replace("[^".$regex_mask."]", "", $item);
+   return preg_replace("/[^".$regex_mask."]/", "", $item);
 }
 
 /* ***********************************************************************
