Index: portstools/tinderbox/webui/index.php
diff -u portstools/tinderbox/webui/index.php:1.24.2.7 portstools/tinderbox/webui/index.php:1.24.2.12
--- portstools/tinderbox/webui/index.php:1.24.2.7	Sun Feb  1 08:32:15 2009
+++ portstools/tinderbox/webui/index.php	Thu May  7 16:02:52 2009
@@ -24,7 +24,7 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/webui/index.php,v 1.24.2.7 2009/02/01 13:32:15 beat Exp $
+# $MCom: portstools/tinderbox/webui/index.php,v 1.24.2.12 2009/05/07 20:02:52 beat Exp $
 #
 
 $starttimer = explode( ' ', microtime() );
@@ -65,44 +65,48 @@
 
 $display_login = $moduleUsers->display_login();
 
-$action = $_REQUEST['action'];
+$action = isset( $_REQUEST['action'] ) ? $_REQUEST['action'] : '';
 
 switch( $action ) {
 	case 'describe_port':		$port_id    = $_REQUEST['id'];
 					$display    = $modulePorts->display_describe_port( $port_id );
 					break;
-	case 'failed_buildports':	$build      = $_REQUEST['build'];
-					$maintainer = $_REQUEST['maintainer'];
-					$display    = $moduleBuildPorts->display_failed_buildports( $build, $maintainer, null, null );
+	case 'failed_buildports':	$build      = isset ( $_REQUEST['build'] ) ? $_REQUEST['build'] : '';
+					$maintainer = isset ( $_REQUEST['maintainer'] ) ? $_REQUEST['maintainer'] : '';
+					$sort       = isset ( $_REQUEST['sort'] ) ? $_REQUEST['sort'] : '';
+					$list_limit_offset = isset ( $_REQUEST['list_limit_offset'] ) ? $_REQUEST['list_limit_offset'] : '0';
+					$display    = $moduleBuildPorts->display_failed_buildports( $build, $maintainer, null, null, $list_limit_offset, $sort );
 					break;
 	case 'buildports_by_reason':	$build      = $_REQUEST['build'];
-					$maintainer = $_REQUEST['maintainer'];
+					$maintainer = isset ( $_REQUEST['maintainer'] ) ? $_REQUEST['maintainer'] : '';
 					$reason = $_REQUEST['reason'];
-					$display    = $moduleBuildPorts->display_failed_buildports( $build, $maintainer, null, $reason );
+					$sort       = isset ( $_REQUEST['sort'] ) ? $_REQUEST['sort'] : '';
+					$list_limit_offset = isset ( $_REQUEST['list_limit_offset'] ) ? $_REQUEST['list_limit_offset'] : '0';
+					$display    = $moduleBuildPorts->display_failed_buildports( $build, $maintainer, null, $reason, $list_limit_offset, $sort );
+					break;
+	case 'bad_buildports':		$build      = isset ( $_REQUEST['build'] ) ? $_REQUEST['build'] : '';
+					$maintainer = isset ( $_REQUEST['maintainer'] ) ? $_REQUEST['maintainer'] : '';
+					$sort       = isset ( $_REQUEST['sort'] ) ? $_REQUEST['sort'] : '';
+					$list_limit_offset = isset ( $_REQUEST['list_limit_offset'] ) ? $_REQUEST['list_limit_offset'] : '0';
+					$display    = $moduleBuildPorts->display_failed_buildports( $build, $maintainer, 'foo', null, $list_limit_offset, $sort );
 					break;
-	case 'bad_buildports':		$build      = $_REQUEST['build'];
-					$maintainer = $_REQUEST['maintainer'];
-					$display    = $moduleBuildPorts->display_failed_buildports( $build, $maintainer, 'foo', null );
-					break;
-	case 'latest_buildports':	$build      = $_REQUEST['build'];
+	case 'latest_buildports':	$build      = isset ( $_REQUEST['build'] ) ? $_REQUEST['build'] : '';
 					$display    = $moduleBuildPorts->display_latest_buildports( $build );
 					break;
 	case 'list_buildports':		$build      = $_REQUEST['build'];
-					$sort       = '';
-					if (isset($_REQUEST['sort'])) {
-						$sort = $_REQUEST['sort'];
-					}
-					$search     = $_REQUEST['search_port_name'];
-					$display    = $moduleBuildPorts->display_list_buildports( $build, $sort, $search );
+					$sort       = isset ( $_REQUEST['sort'] ) ? $_REQUEST['sort'] : '';
+					$search     = isset ( $_REQUEST['search_port_name'] ) ? $_REQUEST['search_port_name'] : '';
+					$list_limit_offset = isset ( $_REQUEST['list_limit_offset'] ) ? $_REQUEST['list_limit_offset'] : '0';
+					$display    = $moduleBuildPorts->display_list_buildports( $build, $sort, $search, $list_limit_offset );
 					break;
-	case 'list_tinderd_queue':	$build_id   = $_REQUEST['filter_build_id'];
+	case 'list_tinderd_queue':	$build_id   = isset ( $_REQUEST['filter_build_id'] ) ? $_REQUEST['filter_build_id'] : '';
 					$display    = $moduleTinderd->list_tinderd_queue( $build_id );
 					break;
 	case 'change_tinderd_queue':	$ctinderdq  = $_REQUEST['change_tinderd_queue'];
 					$entry_id   = $_REQUEST['entry_id'];
 					$build_id   = $_REQUEST['build_id'];
 					$priority   = $_REQUEST['priority'];
-					$emailoc    = $_REQUEST['email_on_completion'];
+					$emailoc    = isset ( $_REQUEST['new_email_on_completion'] ) ? $_REQUEST['new_email_on_completion'] : '';
 					$moduleTinderd->change_tinderd_queue( $ctinderdq, $entry_id, $build_id, $priority, $emailoc );
 					$build_id   = $_REQUEST['filter_build_id'];
 					$display    = $moduleTinderd->list_tinderd_queue( $build_id );
@@ -111,13 +115,13 @@
 					$build_id   = $_REQUEST['new_build_id'];
 					$priority   = $_REQUEST['new_priority'];
 					$directory  = $_REQUEST['new_port_directory'];
-					$emailoc    = $_REQUEST['new_email_on_completion'];
+					$emailoc    = isset ( $_REQUEST['new_email_on_completion'] ) ? $_REQUEST['new_email_on_completion'] : '';
 					$moduleTinderd->add_tinderd_queue( $atinderdq, $build_id, $priority, $directory, $emailoc );
 					$build_id   = $_REQUEST['filter_build_id'];
 					$display    = $moduleTinderd->list_tinderd_queue( $build_id );
 					break;
 	case 'delete_tinderd_queue':	$dtinderdq  = $_REQUEST['delete_tinderd_queue'];
-					$build_id   = $_REQUEST['filter_build_id'];
+					$build_id   = isset ( $_REQUEST['filter_build_id'] ) ? $_REQUEST['filter_build_id'] : '';
 					$moduleTinderd->delete_tinderd_queue( $dtinderdq, $build_id );
 					$display    = $moduleTinderd->list_tinderd_queue( $build_id );
 					break;
@@ -156,7 +160,8 @@
 	case 'config':			$display    = $moduleConfig->display_config();
 					break;
 	case 'latest_buildports_rss':
-					$display    = $moduleRss->display_latest_buildports();
+					$maintainer = isset ( $_REQUEST['maintainer'] ) ? $_REQUEST['maintainer'] : '';
+					$display    = $moduleRss->display_latest_buildports( $maintainer );
 					break;
 	case 'display_markup_log':	$build = $_REQUEST['build'];
 					$id        = $_REQUEST['id'];
