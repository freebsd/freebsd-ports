--- lib/vboxconnector.php	(revision 31)
+++ lib/vboxconnector.php	(revision 32)
@@ -1257,7 +1257,12 @@
 		if($states[$state]['session'] == 'direct') {
 			$this->vbox->openSession($this->session, $vm);
 		} else {
-			$this->vbox->openExistingSession($this->session, $vm, 'vrdp', '');
+
+			// VRDP is not supported in OSE
+			$version = $this->getVersion();
+			$sessionType = ($version['ose'] ? 'headless' : 'vrdp');
+
+			$this->vbox->openExistingSession($this->session, $vm, $sessionType, '');
 		}
 
 		// If this operation returns a progress object save progress
@@ -1335,7 +1340,13 @@
 		try {
 			// create session
 			$this->session = &$this->websessionManager->getSessionObject($this->vbox);
-			$progress = $this->vbox->openRemoteSession($this->session, $vm, 'vrdp', '');
+
+			// VRDP is not supported in OSE
+			$version = $this->getVersion();
+			$sessionType = ($version['ose'] ? 'headless' : 'vrdp');
+
+			$progress = $this->vbox->openRemoteSession($this->session, $vm, $sessionType, '');
+
 		} catch (Exception $e) {
 			// Error opening session
 			$this->errors[] = $e;
@@ -2132,10 +2143,15 @@
 		$progress = $session = null;
 
 		try {
+
+			// VRDP is not supported in OSE
+			$version = $this->getVersion();
+			$sessionType = ($version['ose'] ? 'headless' : 'vrdp');
+
 			// Open session to machine
 			$session = &$this->websessionManager->getSessionObject($this->vbox);
 			if($state == 'Closed') $this->vbox->openSession($session, $args['vm']);
-			else $this->vbox->openExistingSession($session, $args['vm'], 'vrdp', '');
+			else $this->vbox->openExistingSession($session, $args['vm'], $sessionType, '');
 
 			$progress = $session->console->takeSnapshot($args['name'],$args['description']);
 
@@ -2414,7 +2430,12 @@
 			if($args['type'] == 'HardDisk' || $state == 'Closed') {
 				$this->vbox->openSession($this->session, $uuid);
 			} else {
-				$this->vbox->openExistingSession($this->session, $uuid, 'vrdp', '');
+
+				// VRDP is not supported in OSE
+				$version = $this->getVersion();
+				$sessionType = ($version['ose'] ? 'headless' : 'vrdp');
+
+				$this->vbox->openExistingSession($this->session, $uuid, $sessionType, '');
 			}
 
 			foreach($remove as $r) {
@@ -2502,7 +2523,12 @@
 			$this->vbox->openSession($this->session, $args['vm']);
 			$save = true; // force save on closed session as it is not a "run-time" change
 		} else {
-			$this->vbox->openExistingSession($this->session, $args['vm'], 'vrdp', '');
+
+			// VRDP is not supported in OSE
+			$version = $this->getVersion();
+			$sessionType = ($version['ose'] ? 'headless' : 'vrdp');
+
+			$this->vbox->openExistingSession($this->session, $args['vm'], $sessionType, '');
 		}
 
 		$this->session->machine->mountMedium($args['controller'],$args['port'],$args['device'],$args['medium'],true);
