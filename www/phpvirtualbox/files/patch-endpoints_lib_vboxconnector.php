--- endpoints/lib/vboxconnector.php.orig	2017-07-27 16:54:58 UTC
+++ endpoints/lib/vboxconnector.php
@@ -1126,7 +1126,7 @@ class vboxconnector {
 			// Try to register medium.
 			foreach($checks as $iso) {
 				try {
-					$gem = $this->vbox->openMedium($iso,'DVD','ReadOnly');
+					$gem = $this->vbox->openMedium($iso,'DVD','ReadOnly',false);
 					break;
 				} catch (Exception $e) {
 					// Ignore
@@ -1358,7 +1358,7 @@ class vboxconnector {
 			$src = $nsrc->machine;
 		}
 		/* @var $m IMachine */
-		$m = $this->vbox->createMachine($this->vbox->composeMachineFilename($args['name'],null,null),$args['name'],null,null,null,false);
+		$m = $this->vbox->createMachine($this->vbox->composeMachineFilename($args['name'],null,null,null),$args['name'],null,null,null,false);
 		$sfpath = $m->settingsFilePath;
 
 		/* @var $cm CloneMode */
@@ -1522,7 +1522,7 @@ class vboxconnector {
 									$md->releaseRemote();
 								}
 							} else {
-								$med = $this->vbox->openMedium($ma['medium']['location'],$ma['type']);
+								$med = $this->vbox->openMedium($ma['medium']['location'],$ma['type'],'ReadWrite',false);
 							}
 						} else {
 							$med = null;
@@ -1591,7 +1591,7 @@ class vboxconnector {
 			if($state != 'Saved') {
 
 				// Network properties
-				$eprops = $n->getProperties();
+				$eprops = $n->getProperties(null);
 				$eprops = array_combine($eprops[1],$eprops[0]);
 				$iprops = array_map(create_function('$a','$b=explode("=",$a); return array($b[0]=>$b[1]);'),preg_split('/[\r|\n]+/',$args['networkAdapters'][$i]['properties']));
 				$inprops = array();
@@ -1942,7 +1942,7 @@ class vboxconnector {
 			if($args['bootOrder'][$i]) {
 				$m->setBootOrder(($i + 1),$args['bootOrder'][$i]);
 			} else {
-				$m->setBootOrder(($i + 1),null);
+				$m->setBootOrder(($i + 1),'Null');
 			}
 		}
 
@@ -2028,7 +2028,7 @@ class vboxconnector {
 						}
 					} else {
 						/* @var $med IMedium */
-						$med = $this->vbox->openMedium($ma['medium']['location'],$ma['type']);
+						$med = $this->vbox->openMedium($ma['medium']['location'],$ma['type'],'ReadWrite',false);
 					}
 				} else {
 					$med = null;
@@ -2111,7 +2111,7 @@ class vboxconnector {
 			*/
 
 			// Network properties
-			$eprops = $n->getProperties();
+			$eprops = $n->getProperties(null);
 			$eprops = array_combine($eprops[1],$eprops[0]);
 			$iprops = array_map(create_function('$a','$b=explode("=",$a); return array($b[0]=>$b[1]);'),preg_split('/[\r|\n]+/',$args['networkAdapters'][$i]['properties']));
 			$inprops = array();
@@ -2519,7 +2519,7 @@ class vboxconnector {
 	 */
 	public function remote_vboxGetEnumerationMap($args) {
 
-		$c = new $args['class'];
+		$c = new $args['class'](null,null);
 		return (@isset($args['ValueMap']) ? $c->ValueMap : $c->NameMap);
 	}
 
@@ -3697,7 +3697,7 @@ class vboxconnector {
 			$hds = array();
 			$delete = $machine->unregister('DetachAllReturnHardDisksOnly');
 			foreach($delete as $hd) {
-				$hds[] = $this->vbox->openMedium($hd->location,'HardDisk')->handle;
+				$hds[] = $this->vbox->openMedium($hd->location,'HardDisk','ReadWrite',false)->handle;
 			}
 
 			/* @var $progress IProgress */
@@ -3772,7 +3772,7 @@ class vboxconnector {
 			$args['name'] = $_SESSION['user'] . '_' . $args['name'];
 
 		/* Check if file exists */
-		$filename = $this->vbox->composeMachineFilename($args['name'],($this->settings->phpVboxGroups ? '' : $args['group']),$this->vbox->systemProperties->defaultMachineFolder);
+		$filename = $this->vbox->composeMachineFilename($args['name'],($this->settings->phpVboxGroups ? '' : $args['group']),$this->vbox->systemProperties->defaultMachineFolder,null);
 
 		if($this->remote_fileExists(array('file'=>$filename))) {
 			return array('exists' => $filename);
@@ -3874,7 +3874,7 @@ class vboxconnector {
 
 				$sc->releaseRemote();
 
-				$m = $this->vbox->openMedium($args['disk'],'HardDisk');
+				$m = $this->vbox->openMedium($args['disk'],'HardDisk','ReadWrite',false);
 
 				$this->session->machine->attachDevice(trans($HDbusType,'UIMachineSettingsStorage'),0,0,'HardDisk',$m->handle);
 
@@ -3941,7 +3941,7 @@ class vboxconnector {
 			if($at == 'NAT') $nd = $n->NATEngine; /* @var $nd INATEngine */
 			else $nd = null;
 
-			$props = $n->getProperties();
+			$props = $n->getProperties(null);
 			$props = implode("\n",array_map(create_function('$a,$b','return "$a=$b";'),$props[1],$props[0]));
 
 			$adapters[] = array(
@@ -4381,7 +4381,7 @@ class vboxconnector {
 	        }
 
     	    try {
-    	        $this->session->console->addDiskEncryptionPassword($creds['id'], $creds['password'], (bool)@$args['clearOnSuspend']);
+    	        $this->session->console->addDiskEncryptionPassword($creds['id'], $creds['password'], (bool)$creds['clearOnSuspend']);
     	        $response['accepted'][] = $creds['id'];
     		} catch (Exception $e) {
     		    $response['failed'][] = $creds['id'];
@@ -4690,7 +4690,7 @@ class vboxconnector {
 			$machine->lockMachine($this->session->handle, ((string)$machine->sessionState == 'Unlocked' ? 'Write' : 'Shared'));
 
 			/* @var $progress IProgress */
-			list($progress, $snapshotId) = $this->session->machine->takeSnapshot($args['name'], $args['description']);
+			list($progress, $snapshotId) = $this->session->machine->takeSnapshot($args['name'], $args['description'], null);
 
 			// Does an exception exist?
 			try {
@@ -4853,7 +4853,7 @@ class vboxconnector {
 	    // Connect to vboxwebsrv
 	    $this->connect();
 
-	    $m = $this->vbox->openMedium($args['medium'],'HardDisk');
+	    $m = $this->vbox->openMedium($args['medium'],'HardDisk','ReadWrite',false);
 
 	    $retval = $m->checkEncryptionPassword($args['password']);
 
@@ -4874,7 +4874,7 @@ class vboxconnector {
 	    // Connect to vboxwebsrv
 	    $this->connect();
 
-	    $m = $this->vbox->openMedium($args['medium'], 'HardDisk', 'ReadWrite');
+	    $m = $this->vbox->openMedium($args['medium'], 'HardDisk', 'ReadWrite', false);
 
 	    /* @var $progress IProgress */
 	    $progress = $m->changeEncryption($args['old_password'],
@@ -4915,7 +4915,7 @@ class vboxconnector {
 		// Connect to vboxwebsrv
 		$this->connect();
 
-		$m = $this->vbox->openMedium($args['medium'], 'HardDisk');
+		$m = $this->vbox->openMedium($args['medium'], 'HardDisk', 'ReadWrite', false);
 
 		/* @var $progress IProgress */
 		$progress = $m->resize($args['bytes']);
@@ -4953,7 +4953,7 @@ class vboxconnector {
 		$mid = $target->id;
 
 		/* @var $src IMedium */
-		$src = $this->vbox->openMedium($args['src'], 'HardDisk');
+		$src = $this->vbox->openMedium($args['src'], 'HardDisk', 'ReadWrite', false);
 
 		$type = array(($args['type'] == 'fixed' ? 'Fixed' : 'Standard'));
 		if($args['split']) $type[] = 'VmdkSplit2G';
@@ -4991,7 +4991,7 @@ class vboxconnector {
 		$this->connect();
 
 		/* @var $m IMedium */
-		$m = $this->vbox->openMedium($args['medium'], 'HardDisk');
+		$m = $this->vbox->openMedium($args['medium'], 'HardDisk', 'ReadWrite', false);
 		$m->type = $args['type'];
 		$m->releaseRemote();
 
@@ -5074,7 +5074,7 @@ class vboxconnector {
 		// Connect to vboxwebsrv
 		$this->connect();
 
-		return $this->vbox->composeMachineFilename($args['name'],($this->settings->phpVboxGroups ? '' : $args['group']),$this->vbox->systemProperties->defaultMachineFolder);
+		return $this->vbox->composeMachineFilename($args['name'],($this->settings->phpVboxGroups ? '' : $args['group']),$this->vbox->systemProperties->defaultMachineFolder,null);
 
 	}
 
@@ -5129,7 +5129,7 @@ class vboxconnector {
 		$this->connect();
 
 		/* @var $m IMedium */
-		$m = $this->vbox->openMedium($args['medium'],$args['type']);
+		$m = $this->vbox->openMedium($args['medium'],$args['type'],'ReadWrite',false);
 		$mediumid = $m->id;
 
 		// connected to...
@@ -5211,7 +5211,7 @@ class vboxconnector {
 		if(!$args['type']) $args['type'] = 'HardDisk';
 
 		/* @var $m IMedium */
-		$m = $this->vbox->openMedium($args['medium'],$args['type']);
+		$m = $this->vbox->openMedium($args['medium'],$args['type'],'ReadWrite',false);
 
 		if($args['delete'] && @$this->settings->deleteOnRemove && (string)$m->deviceType == 'HardDisk') {
 
@@ -5380,7 +5380,7 @@ class vboxconnector {
 			// Normal medium
 			} else {
 				/* @var $med IMedium */
-				$med = $this->vbox->openMedium($args['medium']['location'],$args['medium']['deviceType']);
+				$med = $this->vbox->openMedium($args['medium']['location'],$args['medium']['deviceType'],'ReadWrite',false);
 			}
 		}
 
@@ -5445,7 +5445,7 @@ class vboxconnector {
 		}
 
 		// For $fixed value
-		$mvenum = new MediumVariant();
+		$mvenum = new MediumVariant(null,null);
 		$variant = 0;
 
 		foreach($m->variant as $mv) {
