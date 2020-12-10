--- carddav.php.orig	2020-12-10 08:52:54 UTC
+++ carddav.php
@@ -349,8 +349,15 @@ class carddav extends rcube_plugin
 
 		if (self::no_override('username', $abook, $prefs)) {
 			// %V parses username for macosx, replaces periods and @ by _, work around bugs in contacts.app
-			$content_username = $abook['username'] === '%V' ? str_replace('@','_', str_replace('.','_',$_SESSION['username'])) : $abook['username'] === '%u' ? $_SESSION['username'] : $abook['username'] === '%l' ? $rcmail->user->get_username('local') : $abook['username'];
-
+			if ($abook['username'] === '%V') {
+				$content_username = str_replace('@','_', str_replace('.','_',$_SESSION['username']));
+			} elseif ($abook['username'] === '%u') {
+				$content_username = $_SESSION['username'];
+			} elseif ($abook['username'] === '%l') {
+				$content_username = $rcmail->user->get_username('local');
+			} else {
+				$content_username = $abook['username'];
+			}
 		} else {
 			// input box for username
 			$input = new html_inputfield(array('name' => $abookid.'_cd_username', 'type' => 'text', 'autocomplete' => 'off', 'value' => $abook['username']));
