--- FlowViewer_Configuration.pm.orig	2013-11-20 17:01:30.000000000 +0600
+++ FlowViewer_Configuration.pm	2013-11-20 17:14:57.000000000 +0600
@@ -59,28 +59,28 @@
 
 # Directories and Files:
 
-$reports_directory       = "/var/www/html/FlowViewer";
-$reports_short           = "/FlowViewer";
-$graphs_directory        = "/var/www/html/FlowGrapher";
-$graphs_short            = "/FlowGrapher";
-$tracker_directory       = "/var/www/html/FlowTracker";
-$tracker_short           = "/FlowTracker";
+$reports_directory       = "%%FLOWVIEWERDIR%%/reports";
+$reports_short           = "/FlowViewer/reports";
+$graphs_directory        = "%%FLOWVIEWERDIR%%/graphs";
+$graphs_short            = "/FlowViewer/graphs";
+$tracker_directory       = "%%FLOWVIEWERDIR%%/tracker";
+$tracker_short           = "/FlowViewer/tracker";
 $old_tracker_directory   = "/var/www/html/FlowTracker_4.2";
-$cgi_bin_directory       = "/var/www/cgi-bin/FlowViewer_4.2.1";
-$cgi_bin_short           = "/cgi-bin/FlowViewer_4.2.1";
-$work_directory          = "/var/www/cgi-bin/FlowViewer_4.2.1/Flow_Working";
-$save_directory          = "/var/www/html/FlowViewer_Saves";
-$save_short              = "/FlowViewer_Saves";
-$names_directory         = "/var/www/cgi-bin/FlowViewer_4.2.1";
-$filter_directory        = "/var/www/cgi-bin/FlowTracker_Files/FlowTracker_Filters";  
-$rrdtool_directory       = "/var/www/cgi-bin/FlowTracker_Files/FlowTracker_RRDtool";
-$dashboard_directory     = "/var/www/html/FlowViewer_Dashboard";
+$cgi_bin_directory       = "%%FLOWVIEWERDIR%%";
+$cgi_bin_short           = "/FlowViewer";
+$work_directory          = "%%FLOWVIEWERDIR%%/working";
+$save_directory          = "%%FLOWVIEWERDIR%%/saves";
+$save_short              = "/FlowViewer/Saves";
+$names_directory         = "%%FLOWVIEWERDIR%%/names";
+$filter_directory        = "%%FLOWVIEWERDIR%%/filters";
+$rrdtool_directory       = "%%FLOWVIEWERDIR%%/rrdtools";
+$dashboard_directory     = "%%FLOWVIEWERDIR%%/FlowViewer_Dashboard";
 $dashboard_short         = "/FlowViewer_Dashboard";
 
-$flow_data_directory     = "/data/flows";
-$exporter_directory      = "/data/flows/all_routers";
-$flow_bin_directory      = "/usr/local/flow-tools/bin";
-$rrdtool_bin_directory   = "/usr/bin";
+$flow_data_directory     = "%%PREFIX%%/var/netflow/";
+$exporter_directory      = "%%PREFIX%%/var/netflow/all_routers";
+$flow_bin_directory      = "%%PREFIX%%/bin";
+$rrdtool_bin_directory   = "%%PREFIX%%/bin";
 
 $silk_data_directory     = "/data/flows";
 $silk_bin_directory      = "/usr/local/bin";
@@ -167,7 +167,7 @@
 # Tracking parameters
  
 $actives_webpage    = "index.html";
-$log_directory      = "/var/www/cgi-bin/FlowViewer_4.2.1/logs";
+$log_directory      = "%%FLOWVIEWERDIR%%/logs";
 $log_collector_short= "Y";
 $log_collector_med  = "N";
 $log_collector_long = "N";
