--- FlowViewer_Configuration.pm.orig	2014-02-24 17:44:27.000000000 +0400
+++ FlowViewer_Configuration.pm	2014-02-24 17:54:45.000000000 +0400
@@ -56,31 +56,31 @@
 
 # Service
 
-$FlowViewer_service      = "https";           # (http, or https)
+$FlowViewer_service      = "http";           # (http, or https)
 
 # Directories and Files:
 
-$reports_directory       = "/var/www/html/FlowViewer";
-$reports_short           = "/FlowViewer";
-$graphs_directory        = "/var/www/html/FlowGrapher";
-$graphs_short            = "/FlowGrapher";
-$tracker_directory       = "/var/www/html/FlowTracker";
-$tracker_short           = "/FlowTracker";
-$cgi_bin_directory       = "/var/www/cgi-bin/FlowViewer_4.3";
-$cgi_bin_short           = "/cgi-bin/FlowViewer_4.3";
-$work_directory          = "/var/www/cgi-bin/FlowViewer_4.3/Flow_Working";
-$save_directory          = "/var/www/html/FlowViewer_Saves";
-$save_short              = "/FlowViewer_Saves";
-$names_directory         = "/var/www/cgi-bin/FlowViewer_4.3";
-$filter_directory        = "/var/www/cgi-bin/FlowTracker_Files/FlowTracker_Filters";  
-$rrdtool_directory       = "/var/www/cgi-bin/FlowTracker_Files/FlowTracker_RRDtool";
-$dashboard_directory     = "/var/www/html/FlowViewer_Dashboard";
+$reports_directory       = "%%FLOWVIEWERDIR%%/reports";
+$reports_short           = "/FlowViewer/reports";
+$graphs_directory        = "%%FLOWVIEWERDIR%%/graphs";
+$graphs_short            = "/FlowViewer/graphs";
+$tracker_directory       = "%%FLOWVIEWERDIR%%/tracker";
+$tracker_short           = "/FlowViewer/tracker";
+$cgi_bin_directory       = "%%FLOWVIEWERDIR%%";
+$cgi_bin_short           = "/FlowViewer";
+$work_directory          = "%%FLOWVIEWERDIR%%/working";
+$save_directory          = "%%FLOWVIEWERDIR%%/saves";
+$save_short              = "/FlowViewer/saves";
+$names_directory         = "%%FLOWVIEWERDIR%%/names";
+$filter_directory        = "%%FLOWVIEWERDIR%%/filters";  
+$rrdtool_directory       = "%%FLOWVIEWERDIR%%/rrdtools";
+$dashboard_directory     = "%%FLOWVIEWERDIR%%/FlowViewer_Dashboard";
 $dashboard_short         = "/FlowViewer_Dashboard";
 
-$flow_data_directory     = "/data/flows";
-$exporter_directory      = "/data/flows/all_routers";
-$flow_bin_directory      = "/usr/local/flow-tools/bin";
-$rrdtool_bin_directory   = "/usr/bin";
+$flow_data_directory     = "/var/db/flows";
+$exporter_directory      = "/var/db/flows/all_routers";
+$flow_bin_directory      = "%%PREFIX%%/bin";
+$rrdtool_bin_directory   = "%%PREFIX%%/bin";
 
 $silk_data_directory     = "/data/flows";
 $silk_bin_directory      = "/usr/local/bin";
@@ -167,7 +167,7 @@
 # Tracking parameters
  
 $actives_webpage    = "index.html";
-$log_directory      = "/var/www/cgi-bin/FlowViewer_4.3/logs";
+$log_directory      = "%%FLOWVIEWERDIR%%/logs";
 $log_collector_short= "Y";
 $log_collector_med  = "N";
 $log_collector_long = "N";
