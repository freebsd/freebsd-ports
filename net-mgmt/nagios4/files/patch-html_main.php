--- html/main.php.orig	2026-01-14 16:37:00 UTC
+++ html/main.php
@@ -69,37 +69,6 @@ if ($theme != 'dark' && $theme != 'light') {
 
 <body id="splashpage">
 
-<div id="currentversioninfo">
-	<div>
-		<div class="version">Version <b><?php echo $this_version; ?></b></div>
-		<div class="releasedate">January 14, 2026</div>
-	</div>
-	<div><span id="core-status"></span></div>
-	<a class="checkforupdates" href="https://www.nagios.org/checkforupdates/?version=<?php echo $this_version; ?>&amp;product=nagioscore" target="_blank">Check for updates</a>
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
-	} else if ($updateinfo['update_available'] && $this_version < $updateinfo['update_version']) {
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
 <div id="mainsplash">
 	<a href="https://www.nagios.org/?utm_campaign=csp&utm_source=nagioscore&utm_medium=splash_thumbnail&utm_content=<?php echo $this_version; ?>" target="_blank"><img src="images/csp-dashboard.avif" /></a>
 	<div id="splashtext">
