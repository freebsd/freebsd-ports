--- lib/AJAXTree.php.orig	2021-12-12 02:35:51 UTC
+++ lib/AJAXTree.php
@@ -31,7 +31,7 @@ class AJAXTree extends HTMLTree {
 		# Level pre-treatment
 		$code = '';
 		if (is_string($level)) {
-			for ($i=0; $i<strlen($level); $i++) {
+			for ($i=0; $i<strlen((string) $level); $i++) {
 				if ($level[$i] == '0')
 					$code .= '0';
 				elseif ($level[$i] == '1')
@@ -41,7 +41,7 @@ class AJAXTree extends HTMLTree {
 		} elseif ($level > 0)
 			$code = '0' * $level;
 
-		$level = strlen($code);
+		$level = strlen((string) $code);
 
 		# Get entry to display as node
 		$entry = $this->getEntry($item);
@@ -189,7 +189,7 @@ class AJAXTree extends HTMLTree {
 
 		$indent = '';
 
-		for ($i=0; $i<strlen($code); $i++) {
+		for ($i=0; $i<strlen((string) $code); $i++) {
 			switch ($code[$i]) {
 				case '0':
 					$indent .= sprintf('<img src="%s/tree_space.png" alt="  " class="imgs" style="border: 0px; vertical-align:text-top;" />',IMGDIR);
@@ -223,7 +223,7 @@ class AJAXTree extends HTMLTree {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',33,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-		if (strlen($level) == 0)
+		if (strlen((string) $level) == 0)
 			return '';
 
 		$server = $this->getServer();
@@ -243,7 +243,7 @@ class AJAXTree extends HTMLTree {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',33,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-		if (strlen($level) == 0)
+		if (strlen((string) $level) == 0)
 			return '';
 
 		$server = $this->getServer();
