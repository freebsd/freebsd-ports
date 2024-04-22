--- html/main.php.orig	2024-03-16 10:46:27.911029000 +0100
+++ html/main.php	2024-03-16 10:48:12.929841000 +0100
@@ -142,38 +142,6 @@ $this_year = '2024';
 </div>
 
 
-<div id="currentversioninfo">
-	<div class="product">Nagios<sup><span style="font-size: small;">&reg;</span></sup> Core<sup><span style="font-size: small;">&trade;</span></sup></div>
-	<div class="version">Version <?php echo $this_version; ?></div>
-	<div class="releasedate">February 28, 2024</div>
-	<div class="checkforupdates"><a href="https://www.nagios.org/checkforupdates/?version=<?php echo $this_version; ?>&amp;product=nagioscore" target="_blank">Check for updates</a></div>
-</div>
-
-
-<div id="updateversioninfo">
-<?php
-	$updateinfo = get_update_information();
-	if (!$updateinfo['update_checks_enabled']) {
-?>
-		<div class="updatechecksdisabled">
-			<div class="warningmessage">Warning: Automatic Update Checks are Disabled!</div>
-			<div class="submessage">Disabling update checks presents a possible security risk.  Visit <a href="https://www.nagios.org/" target="_blank">nagios.org</a> to check for updates manually or enable update checks in your Nagios config file.</a></div>
-		</div>
-<?php
-	} else if (
-		$updateinfo['update_available'] && $this_version < $updateinfo['update_version']
-	) {
-?>
-		<div class="updateavailable">
-			<div class="updatemessage">A new version of Nagios Core is available!</div>
-			<div class="submessage">Visit <a href="https://www.nagios.org/download/" target="_blank">nagios.org</a> to download Nagios <?php echo htmlentities($updateinfo['update_version'], ENT_QUOTES, 'UTF-8');?>.</div>
-		</div>
-<?php
-	}
-?>
-</div>
-
-
 <div id='splashrow0'>
 	<div id="splashbox0" class="splashbox-media"><!-- info banner feed -->
 		<div id="splashbox0-contents"></div>
