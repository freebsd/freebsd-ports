--- lib/page.php.orig	2021-12-12 02:35:51 UTC
+++ lib/page.php
@@ -184,7 +184,7 @@ class page {
 		$empty = true;
 		if (function_exists('cmd_control_pane'))
 			foreach (cmd_control_pane('main') as $cmddetails)
-				if ((isset($cmddetails['enable']) && trim($cmddetails['enable'])) || ! isset($cmddetails['enable'])) {
+				if ((isset($cmddetails['enable']) && trim((string) $cmddetails['enable'])) || ! isset($cmddetails['enable'])) {
 					if (! $empty)
 						echo ' | ';
 
@@ -358,7 +358,7 @@ class page {
 
 			if (defined('DEBUG_ENABLED') && DEBUG_ENABLED)
 				debug_log('Sending COMPRESSED output to browser[(%s),%s]',129,0,__FILE__,__LINE__,__METHOD__,
-					strlen($output),$output);
+					strlen((string) $output),$output);
 
 			print gzencode($output);
 		}
@@ -445,7 +445,7 @@ class page {
 
 			if (defined('DEBUG_ENABLED') && DEBUG_ENABLED)
 				debug_log('Sending COMPRESSED output to browser[(%s),%s]',129,0,__FILE__,__LINE__,__METHOD__,
-					strlen($output),$output);
+					strlen((string) $output),$output);
 
 			print gzencode($output);
 		}
