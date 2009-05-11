Index: portstools/tinderbox/webui/module/modulePorts.php
diff -u portstools/tinderbox/webui/module/modulePorts.php:1.12.2.4 portstools/tinderbox/webui/module/modulePorts.php:1.12.2.5
--- portstools/tinderbox/webui/module/modulePorts.php:1.12.2.4	Sun Feb  1 14:43:27 2009
+++ portstools/tinderbox/webui/module/modulePorts.php	Wed May  6 15:07:01 2009
@@ -24,7 +24,7 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/webui/module/modulePorts.php,v 1.12.2.4 2009/02/01 19:43:27 beat Exp $
+# $MCom: portstools/tinderbox/webui/module/modulePorts.php,v 1.12.2.5 2009/05/06 19:07:01 beat Exp $
 #
 
 require_once 'module/module.php';
@@ -57,8 +57,14 @@
 			$ports_tree = $this->TinderboxDS->getPortsTreeForBuild( $build );
 			if( empty( $ports_tree_ids[$ports_tree->getId()] ) ) {
 				$ports_tree_ids[$ports_tree->getId()] = 1;
-
-				list( $cvsweb, $cvsweb_querystr ) = explode( '?', $ports_tree->getCVSwebURL(), 2 );
+				
+				$cvsweb_arr = explode( '?', $ports_tree->getCVSwebURL(), 2 );
+				if ( count( $cvsweb_arr ) == 1 ) {
+					list( $cvsweb ) = $cvsweb_arr;
+					$cvsweb_querystr = '';
+				} else {
+					list( $cvsweb, $cvsweb_querystr ) = $cvsweb_arr;
+				}
 
 				if ( $cvsweb_querystr ) {
 					$cvsweb = rtrim( $cvsweb, '/' );
