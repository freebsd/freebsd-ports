--- library/vendor/lessphp/lessc.inc.php.orig	2019-10-18 05:39:24 UTC
+++ library/vendor/lessphp/lessc.inc.php
@@ -662,7 +662,7 @@ class lessc {
 
 		// check for a rest
 		$last = end($args);
-		if ($last[0] == "rest") {
+		if (is_array($last) && $last[0] == "rest") {
 			$rest = array_slice($orderedValues, count($args) - 1);
 			$this->set($last[1], $this->reduce(array("list", " ", $rest)));
 		}
