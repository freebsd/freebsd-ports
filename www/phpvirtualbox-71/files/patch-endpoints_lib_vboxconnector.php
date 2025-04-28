--- endpoints/lib/vboxconnector.php.orig	2025-03-09 01:02:03 UTC
+++ endpoints/lib/vboxconnector.php
@@ -113,6 +113,8 @@ class vboxconnector {
 	 */
 	var $dsep = null;
 
+	var $client = null;
+
 	/**
 	 * Obtain configuration settings and set object vars
 	 * @param boolean $useAuthMaster use the authentication master obtained from configuration class
@@ -388,7 +390,8 @@ class vboxconnector {
 
 			// The amount of time we will wait for events is determined by
 			// the amount of listeners - at least half a second
-			$listenerWait = max(100,intval(500/count($this->persistentRequest['vboxEventListeners'])));
+			$listenerCount = count($this->persistentRequest['vboxEventListeners']);
+			$listenerWait = max(100,intval(500/($listenerCount > 0 ? $listenerCount : 1)));
 		}
 
 		// Get events from each configured event listener
