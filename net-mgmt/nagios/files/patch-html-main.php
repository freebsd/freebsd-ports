--- html/main.php.orig	2012-05-12 09:30:53.000000000 +0930
+++ html/main.php	2012-05-21 21:37:23.000000000 +0930
@@ -40,35 +40,10 @@
 <div class="product">Nagios<sup><span style="font-size: small;">&reg;</span></sup> Core<sup><span style="font-size: small;">&trade;</span></sup></div>
 <div class="version">Version 3.4.1</div>
 <div class="releasedate">May 11, 2012</div>
-<div class="checkforupdates"><a href="http://www.nagios.org/checkforupdates/?version=3.4.1&product=nagioscore" target="_blank">Check for updates</a></div>
 <!--<div class="whatsnew"><a href="http://go.nagios.com/nagioscore/whatsnew">Read what's new in Nagios Core 3</a></div>-->
 </div>
 
 
-<div id="updateversioninfo">
-<?php
-	$updateinfo=get_update_information();
-	//print_r($updateinfo);
-	//$updateinfo['update_checks_enabled']=false;
-	//$updateinfo['update_available']=true;
-	if($updateinfo['update_checks_enabled']==false){
-?>
-		<div class="updatechecksdisabled">
-		<div class="warningmessage">Warning: Automatic Update Checks are Disabled!</div>
-		<div class="submessage">Disabling update checks presents a possible security risk.  Visit <a href="http://www.nagios.org/" target="_blank">nagios.org</a> to check for updates manually or enable update checks in your Nagios config file.</a></div>
-		</div>
-<?php
-		}
-	else if($updateinfo['update_available']==true && $this_version!=$updateinfo['update_version']){
-?>
-		<div class="updateavailable">
-		<div class="updatemessage">A new version of Nagios Core is available!</div>
-		<div class="submessage">Visit <a href="http://www.nagios.org/download/" target="_blank">nagios.org</a> to download Nagios <?php echo $updateinfo['update_version'];?>.</div>
-		</div>
-<?php
-		}
-?>
-</div>
 
 
 
