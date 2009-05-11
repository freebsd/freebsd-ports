Index: portstools/tinderbox/webui/module/moduleBuildPorts.php
diff -u portstools/tinderbox/webui/module/moduleBuildPorts.php:1.16.2.5 portstools/tinderbox/webui/module/moduleBuildPorts.php:1.16.2.7
--- portstools/tinderbox/webui/module/moduleBuildPorts.php:1.16.2.5	Sun Feb  1 08:32:16 2009
+++ portstools/tinderbox/webui/module/moduleBuildPorts.php	Wed May  6 16:37:53 2009
@@ -24,7 +24,7 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/webui/module/moduleBuildPorts.php,v 1.16.2.5 2009/02/01 13:32:16 beat Exp $
+# $MCom: portstools/tinderbox/webui/module/moduleBuildPorts.php,v 1.16.2.7 2009/05/06 20:37:53 beat Exp $
 #
 
 require_once 'module/module.php';
@@ -37,8 +37,8 @@
 		$this->modulePorts = $modulePorts;
 	}
 
-	function display_list_buildports( $build_name, $sort, $search_port_name ) {
-		global $starttimer, $with_timer;
+	function display_list_buildports( $build_name, $sort, $search_port_name, $list_limit_offset ) {
+		global $list_limit_nr, $starttimer, $with_timer;
 
 		$build = $this->TinderboxDS->getBuildByName( $build_name );
 		if ( ! $build ) {
@@ -46,7 +46,7 @@
 			$this->template_assign( 'no_list', true );
 			return $this->template_parse( 'list_buildports.tpl' );
 		}
-		$ports = $this->TinderboxDS->getPortsForBuild( $build, $sort, $search_port_name );
+		$ports = $this->TinderboxDS->getPortsForBuild( $build, $sort, $search_port_name, $list_limit_nr, $list_limit_offset );
 		$ports_tree = $this->TinderboxDS->getPortsTreeById( $build->getPortsTreeId() );
 		$jail = $this->TinderboxDS->getJailById( $build->getJailId() );
 
@@ -82,6 +82,23 @@
 			$qs[$kv[0]] = $kv[1];
 		}
 
+		if ( !isset( $list_limit_nr ) || $list_limit_nr == '0' ) {
+			$list_limit_nr = 0;
+			$list_nr_prev = -1;
+			$list_nr_next = 0;
+		} else {
+			if ( ( $list_limit_offset - $list_limit_nr ) < 0 ) {
+				$list_nr_prev = -1;
+			} else {
+				$list_nr_prev = $list_limit_offset - $list_limit_nr;
+			}
+			if ( count( $ports ) < $list_limit_nr ) {
+				$list_nr_next = 0;
+			} else {
+				$list_nr_next = $list_limit_offset + $list_limit_nr;
+			}
+		}
+
 		$this->template_assign( 'port_fail_reasons',      $port_fail_reasons );
 		$this->template_assign( 'maintainers',            $this->TinderboxDS->getAllMaintainers() );
 		$this->template_assign( 'build_description',      $build->getDescription() );
@@ -93,6 +110,8 @@
 		$this->template_assign( 'ports_tree_lastbuilt',   prettyDatetime( $ports_tree->getLastBuilt() ) );
 		$this->template_assign( 'local_time',             prettyDatetime( date( 'Y-m-d H:i:s' ) ) );
 		$this->template_assign( 'search_port_name',       htmlentities( $search_port_name ) );
+		$this->template_assign( 'list_nr_prev',           $list_nr_prev );
+		$this->template_assign( 'list_nr_next',           $list_nr_next );
 		$elapsed_time = '';
 		if (isset($with_timer) && $with_timer == 1) {
 			$elapsed_time = get_ui_elapsed_time($starttimer);
@@ -103,8 +122,8 @@
 		return $this->template_parse( 'list_buildports.tpl' );
 	}
 
-	function display_failed_buildports( $build_name, $maintainer, $all, $wanted_reason  ) {
-		global $with_timer, $starttimer;
+	function display_failed_buildports( $build_name, $maintainer, $all, $wanted_reason, $list_limit_offset, $sort ) {
+		global $list_limit_nr, $with_timer, $starttimer;
 
 		if( $build_name ) {
 			$build = $this->TinderboxDS->getBuildByName( $build_name );
@@ -119,13 +138,13 @@
 		}
 
 		if ($wanted_reason) {
-			$ports = $this->TinderboxDS->getPortsByStatus( $build_id, NULL, $wanted_reason, '' );
+			$ports = $this->TinderboxDS->getPortsByStatus( $build_id, NULL, $wanted_reason, '', $list_limit_nr, $list_limit_offset, $sort );
 		}
 		else {
 			if ($all) {
-				$ports = $this->TinderboxDS->getPortsByStatus( $build_id, $maintainer, '', 'SUCCESS' );
+				$ports = $this->TinderboxDS->getPortsByStatus( $build_id, $maintainer, '', 'SUCCESS', $list_limit_nr, $list_limit_offset, $sort );
 			} else {
-				$ports = $this->TinderboxDS->getPortsByStatus( $build_id, $maintainer, 'FAIL', '' );
+				$ports = $this->TinderboxDS->getPortsByStatus( $build_id, $maintainer, 'FAIL', '', $list_limit_nr, $list_limit_offset, $sort );
 			}
 		}
 
@@ -153,16 +172,44 @@
 			}
 		}
 
+		$qs = array();
+		$qkvs = explode( '&', $_SERVER['QUERY_STRING'] );
+		foreach ( $qkvs as $qkv ) {
+			$kv = explode( '=', $qkv );
+			$qs[$kv[0]] = $kv[1];
+		}
+
+		if ( !isset( $list_limit_nr ) || $list_limit_nr == '0' ) {
+			$list_limit_nr = 0;
+			$list_nr_prev = -1;
+			$list_nr_next = 0;
+		} else {
+			if ( ( $list_limit_offset - $list_limit_nr ) < 0 ) {
+				$list_nr_prev = -1;
+			} else {
+				$list_nr_prev = $list_limit_offset - $list_limit_nr;
+			}
+	
+			if ( count( $ports ) < $list_limit_nr ) {
+				$list_nr_next = 0;
+			} else {
+				$list_nr_next = $list_limit_offset + $list_limit_nr;
+			}
+		}
+
 		$this->template_assign( 'port_fail_reasons',      $port_fail_reasons );
 		$this->template_assign( 'build_name', $build_name );
 		$this->template_assign( 'maintainer', $maintainer );
 		$this->template_assign( 'local_time', prettyDatetime( date( 'Y-m-d H:i:s' ) ) );
+		$this->template_assign( 'querystring',$qs );
 		$elapsed_time = '';
 		if (isset($with_timer) && $with_timer == 1) {
 			$elapsed_time = get_ui_elapsed_time($starttimer);
 		}
 		$this->template_assign( 'ui_elapsed_time',           $elapsed_time);
 		$this->template_assign( 'reason',                    $wanted_reason );
+		$this->template_assign( 'list_nr_prev',              $list_nr_prev );
+		$this->template_assign( 'list_nr_next',              $list_nr_next );
 
 		return $this->template_parse( 'failed_buildports.tpl' );
 	}
