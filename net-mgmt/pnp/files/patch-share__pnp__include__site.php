--- ./share/pnp/include/site.php.orig	2010-05-29 23:27:44.000000000 +0200
+++ ./share/pnp/include/site.php	2010-05-29 23:27:44.000000000 +0200
@@ -30,7 +30,7 @@
 				$a = 0;
 						
 				while (isset($file[$l]) && $file[$l] != "") {
-					if(!ereg("^#",$file[$l]) && !ereg("^;",$file[$l])) {
+					if(!preg_match("/^#/",$file[$l]) && !preg_match("/^;/",$file[$l])) {
 						$defineCln = explode("{", $file[$l]);
 						$define = explode(" ",$defineCln[0]);
 						if (isset($define[1]) && in_array(trim($define[1]),$type)) {
