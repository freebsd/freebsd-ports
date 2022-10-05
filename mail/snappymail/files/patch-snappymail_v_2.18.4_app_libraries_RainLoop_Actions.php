--- snappymail/v/2.18.4/app/libraries/RainLoop/Actions.php.orig	2022-10-04 10:05:02 UTC
+++ snappymail/v/2.18.4/app/libraries/RainLoop/Actions.php
@@ -749,7 +749,6 @@ class Actions
 					'HideUnsubscribed' => false,
 					'HideDeleted' => true,
 					'UnhideKolabFolders' => false,
-					'MainEmail' => '',
 					'UserBackgroundName' => '',
 					'UserBackgroundHash' => '',
 					'SieveAllowFileintoInbox' => (bool)$oConfig->Get('labs', 'sieve_allow_fileinto_inbox', false)
