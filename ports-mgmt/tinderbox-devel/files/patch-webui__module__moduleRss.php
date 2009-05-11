Index: portstools/tinderbox/webui/module/moduleRss.php
diff -u portstools/tinderbox/webui/module/moduleRss.php:1.1.2.2 portstools/tinderbox/webui/module/moduleRss.php:1.1.2.3
--- portstools/tinderbox/webui/module/moduleRss.php:1.1.2.2	Sun Feb  1 08:32:16 2009
+++ portstools/tinderbox/webui/module/moduleRss.php	Wed May  6 15:21:54 2009
@@ -36,12 +36,12 @@
 		$this->modulePorts = $modulePorts;
 	}
 
-	function display_latest_buildports( $limit = 20 ) {
+	function display_latest_buildports( $maintainer, $limit = 20 ) {
 		global $wwwrooturi;
 
 		$ports = array();
 
-		foreach ( $this->TinderboxDS->getLatestPorts( false, $limit ) as $port ) {
+		foreach ( $this->TinderboxDS->getLatestPorts( false, $limit, $maintainer ) as $port ) {
 			$build = $this->TinderboxDS->getBuildById( $port->getBuildId() );
 			$jail = $this->TinderboxDS->getJailById( $build->getJailId() );
 
