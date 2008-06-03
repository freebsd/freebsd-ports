--- ./www-exp/module/moduleBuildPorts.php.orig	2008-06-03 15:53:53.000000000 +0300
+++ ./www-exp/module/moduleBuildPorts.php	2008-06-03 15:54:42.000000000 +0300
@@ -145,7 +145,7 @@
 			$build_id = false;
 		}
 
-		$ports = $this->TinderboxDS->getLatestPorts( $build_id, 20 );
+		$ports = $this->TinderboxDS->getLatestPorts( $build_id, 30 );
 
 		if( is_array( $ports ) && count( $ports ) > 0 ) {
 			$this->template_assign( 'data', $this->modulePorts->get_list_data( $build_name, $ports ) );
