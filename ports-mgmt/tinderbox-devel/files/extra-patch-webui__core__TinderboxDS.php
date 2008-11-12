--- ./webui/core/TinderboxDS.php.orig	2008-11-12 17:35:47.000000000 +0200
+++ ./webui/core/TinderboxDS.php	2008-11-12 17:36:48.000000000 +0200
@@ -378,6 +378,10 @@
 	    if ($sortby == "") $sortby = "port_directory";
 	    if ($sortby == "port_directory") $sortbytable = "p";
 	    if ($sortby == "port_maintainer") $sortbytable = "p";
+	    if ($sortby == "last_built") {
+		$sortbytable = "bp";
+		$sortby = "last_built desc";
+	    }
             $query = "SELECT p.*,
                              bp.last_built,
                              bp.last_status,
