--- ./webui/module/moduleBuildPorts.php.orig	2008-11-12 17:38:36.000000000 +0200
+++ ./webui/module/moduleBuildPorts.php	2008-11-12 17:38:01.000000000 +0200
@@ -168,7 +168,7 @@
 			$build_id = false;
 		}
 
-		$ports = $this->TinderboxDS->getLatestPorts( $build_id, 20 );
+		$ports = $this->TinderboxDS->getLatestPorts( $build_id, 30 );
 
 		if( is_array( $ports ) && count( $ports ) > 0 ) {
 			$this->template_assign( 'data', $this->modulePorts->get_list_data( $build_name, $ports ) );
