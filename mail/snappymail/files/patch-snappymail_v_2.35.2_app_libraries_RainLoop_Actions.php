--- snappymail/v/2.35.2/app/libraries/RainLoop/Actions.php.orig	2024-03-08 05:14:45 UTC
+++ snappymail/v/2.35.2/app/libraries/RainLoop/Actions.php
@@ -668,7 +668,7 @@ class Actions
 					$sPassword = \substr(\base64_encode(\random_bytes(16)), 0, 12);
 					Utils::saveFile($passfile, $sPassword . "\n");
 //					\chmod($passfile, 0600);
-					$oConfig->SetPassword($sPassword);
+					$oConfig->SetPassword(new \SnappyMail\SensitiveString($sPassword));
 					$oConfig->Save();
 				}
 			}
