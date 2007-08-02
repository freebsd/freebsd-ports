
$FreeBSD$

--- html/nfsen.php.orig
+++ html/nfsen.php
@@ -489,7 +489,8 @@
 		if ( count($BookmarkVars) == count($_vars) ) {
 			for ( $i=0; $i<count($BookmarkVars); $i++ ) {
 				if ( $_vars[$i] != '-' ) 
-					$_POST[$BookmarkVars[$i]] = $_vars[$i];
+					$_POST[$BookmarkVars[$i]] = 
+						str_replace('!','|',$_vars[$i]);
 			}
 		} else {
 			SetMessage('warning', "Bookmark processing error");
@@ -749,7 +750,16 @@
 // Generate bookmark
 $vars = array();
 foreach ( $BookmarkVars as $var ) {
-	$vars[] = array_key_exists($var, $_SESSION) ? $_SESSION[$var] : '-';
+	if (array_key_exists($var, $_SESSION)) {
+		$vars[] = $_SESSION[$var];
+	}
+	elseif (array_key_exists('detail_opts', $_SESSION) and
+			array_key_exists($var, $_SESSION['detail_opts'])) {
+		$vars[] = str_replace('|','!',$_SESSION['detail_opts'][$var]);
+	}
+	else {
+		$vars[] = '-';
+	}
 }
 
 $_SESSION['bookmark'] = urlencode(base64_encode(implode('|', $vars)));
