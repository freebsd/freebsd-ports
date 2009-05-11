Index: portstools/tinderbox/webui/core/TinderboxDS.php
diff -u portstools/tinderbox/webui/core/TinderboxDS.php:1.36.2.6 portstools/tinderbox/webui/core/TinderboxDS.php:1.36.2.12
--- portstools/tinderbox/webui/core/TinderboxDS.php:1.36.2.6	Sun Feb  1 14:43:27 2009
+++ portstools/tinderbox/webui/core/TinderboxDS.php	Thu May  7 03:08:03 2009
@@ -24,7 +24,7 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $MCom: portstools/tinderbox/webui/core/TinderboxDS.php,v 1.36.2.6 2009/02/01 19:43:27 beat Exp $
+# $MCom: portstools/tinderbox/webui/core/TinderboxDS.php,v 1.36.2.12 2009/05/07 07:08:03 beat Exp $
 #
 
     require_once 'DB.php';
@@ -377,7 +377,7 @@
             return $results[0];
         }
 
-        function getPortsForBuild( $build, $sortby = 'port_directory', $port_name = '' ) {
+        function getPortsForBuild( $build, $sortby = 'port_directory', $port_name = '', $limit = 0 , $limit_offset = 0 ) {
 	    $sortbytable = "bp";
 	    if ($sortby == "") $sortby = "port_directory";
 	    if ($sortby == "port_directory") $sortbytable = "p";
@@ -388,7 +388,7 @@
 	    }
             $query = "SELECT p.port_id,
                              p.port_directory,
-                             TRIM(TRAILING '@FreeBSD.org' FROM p.port_maintainer) as port_maintainer,
+                             REPLACE(p.port_maintainer, '@FreeBSD.org', '') as port_maintainer,
                              p.port_name,
                              p.port_comment,
                              bp.last_built,
@@ -409,6 +409,8 @@
             if ( $port_name )
                  $query .= " AND p.port_name LIKE '%" . $this->db->escapeSimple( $port_name ) . "%'";
             $query .= " ORDER BY " . $this->db->escapeSimple( $sortbytable ) . "." . $this->db->escapeSimple( $sortby );
+            if( $limit != 0 )
+                $query .= " LIMIT " . $this->db->escapeSimple( $limit_offset ) . "," .  $this->db->escapeSimple( $limit );
 
             $rc = $this->_doQueryHashRef($query, $results, $build->getId());
 
@@ -421,7 +423,7 @@
             return $ports;
         }
 
-        function getLatestPorts($build_id,$limit="") {
+        function getLatestPorts( $build_id, $limit = '', $maintainer = '' ) {
             $query = "SELECT p.*,
                              bp.build_id,
                              bp.last_built,
@@ -441,6 +443,8 @@
                          AND bp.last_built IS NOT NULL ";
             if($build_id)
                  $query .= "AND bp.build_id=" . $this->db->escapeSimple( $build_id );
+            if( $maintainer )
+                 $query .= " AND p.port_maintainer='" . $this->db->escapeSimple( $maintainer ) . "' ";
             $query .= " ORDER BY bp.last_built DESC ";
             if($limit)
                  $query .= " LIMIT " . $this->db->escapeSimple( $limit );
@@ -483,7 +487,15 @@
 	}
 
 
-        function getPortsByStatus($build_id,$maintainer,$status,$notstatus) {
+        function getPortsByStatus( $build_id, $maintainer, $status, $notstatus, $limit = 0 , $limit_offset = 0, $sortby = 'last_built' ) {
+  	        $sortbytable = 'bp';
+  	        if ( $sortby == '' ) $sortby = 'port_directory';
+  	        if ( $sortby == 'port_directory' ) $sortbytable = 'p';
+  	        if ( $sortby == 'port_maintainer' ) $sortbytable = 'p';
+  	        if ( $sortby == 'last_built' ) {
+  	            $sortbytable = 'bp';
+  	            $sortby = 'last_built desc';
+  	        }
             $query = "SELECT p.*,
                              bp.build_id,
                              bp.last_built,
@@ -509,7 +521,9 @@
 		 $query .= "AND bp.last_status<>'" . $this->db->escapeSimple( $notstatus ) . "' AND bp.last_status<>'UNKNOWN' ";
             if($maintainer)
                  $query .= "AND p.port_maintainer='" . $this->db->escapeSimple( $maintainer ) . "' ";
-            $query .= " ORDER BY bp.last_built DESC ";
+            $query .= " ORDER BY " . $this->db->escapeSimple( $sortbytable ) . "." . $this->db->escapeSimple( $sortby );
+            if( $limit != 0 )
+                 $query .= " LIMIT " . $this->db->escapeSimple( $limit_offset ) . "," . $limit;
 
             $rc = $this->_doQueryHashRef($query, $results, array());
 
@@ -540,7 +554,7 @@
         function getPortById($id) {
             $results = $this->getPorts(array( 'port_id' => $id ));
 
-            if (is_null($results)) {
+            if ( is_null( $results ) || empty( $results ) ) {
                 return null;
             }
 
@@ -561,6 +575,11 @@
 	    $query = 'SELECT port_id AS id FROM build_ports WHERE build_id = ? AND currently_building = \'1\'';
 	    $rc = $this->_doQueryHashRef($query, $results, array($build_id));
 	    if (!$rc) return null;
+ 
+	    if ( empty( $results ) ) {
+	        return null;
+	    }
+
 	    $port = $this->getPortById($results[0]['id']);
 
 	    return $port;
