--- ./www-exp/core/TinderboxDS.php.orig	2008-06-02 07:11:02.000000000 +0300
+++ ./www-exp/core/TinderboxDS.php	2008-06-03 15:38:24.000000000 +0300
@@ -372,6 +372,11 @@
             if ($sortby == "") $sortby = "Port_Directory";
             if ($sortby == "Port_Directory") $sortbytable = "p";
             if ($sortby == "Port_Maintainer") $sortbytable = "p";
+            if ($sortby == "Last_Built") {
+		$sortbytable = "bp";
+		$sortby = "Last_Built desc";
+            }
+
             $query = "SELECT p.*,
                              bp.Last_Built,
                              bp.Last_Status,
