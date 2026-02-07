--- FlowViewer_Configuration.pm.orig	2014-11-10 11:04:45.000000000 +0300
+++ FlowViewer_Configuration.pm	2014-11-10 11:25:39.000000000 +0300
@@ -64,36 +64,36 @@
 
 # Service
 
-$FlowViewer_service      = "https";           # (http, or https)
+$FlowViewer_service      = "http";           # (http, or https)
 
 # Directories and Files:
 
-$reports_directory       = "/var/www/html/FlowViewer";
-$reports_short           = "/FlowViewer";
-$graphs_directory        = "/var/www/html/FlowGrapher";
-$graphs_short            = "/FlowGrapher";
-$monitor_directory       = "/var/www/html/FlowMonitor";
-$monitor_short           = "/FlowMonitor";
-$cgi_bin_directory       = "/var/www/cgi-bin/FlowViewer_4.5";
-$cgi_bin_short           = "/cgi-bin/FlowViewer_4.5";
-$work_directory          = "/var/www/cgi-bin/FlowViewer_4.5/Flow_Working";
-$save_directory          = "/var/www/html/FlowViewer_Saves";
-$save_short              = "/FlowViewer_Saves";
-$names_directory         = "/var/www/cgi-bin/FlowViewer_4.5";
-$ipset_directory         = "/var/www/cgi-bin/FlowViewer_4.5";     # Where FlowViewer can find IPset files
-$filter_directory        = "/var/www/cgi-bin/FlowMonitor_Files/FlowMonitor_Filters";  
-$rrdtool_directory       = "/var/www/cgi-bin/FlowMonitor_Files/FlowMonitor_RRDtool";
-$dashboard_directory     = "/var/www/html/FlowViewer_Dashboard";
+$reports_directory       = "%%FLOWVIEWERDIR%%/reports";
+$reports_short           = "/FlowViewer/reports";
+$graphs_directory        = "%%FLOWVIEWERDIR%%/graphs";
+$graphs_short            = "/FlowViewer/graphs";
+$monitor_directory       = "%%FLOWVIEWERDIR%%/monitor";
+$monitor_short           = "/FlowMonitor/monitor";
+$cgi_bin_directory       = "%%FLOWVIEWERDIR%%";
+$cgi_bin_short           = "/FlowViewer";
+$work_directory          = "%%FLOWVIEWERDIR%%/working";
+$save_directory          = "%%FLOWVIEWERDIR%%/saves";
+$save_short              = "/FlowViewer/saves";
+$names_directory         = "%%FLOWVIEWERDIR%%/names";
+$ipset_directory         = "%%FLOWVIEWERDIR%%/ipsets";     # Where FlowViewer can find IPset files
+$filter_directory        = "%%FLOWVIEWERDIR%%/filters";  
+$rrdtool_directory       = "%%FLOWVIEWERDIR%%/rrdtools";
+$dashboard_directory     = "%%FLOWVIEWERDIR%%/FlowViewer_Dashboard";
 $dashboard_short         = "/FlowViewer_Dashboard";
 #@other_dashboards       = ();          # Set to empty if you have just the one nominal Dashboard
-@other_dashboards        = ("/var/www/html/SOC","/var/www/html/NetOps");
+@other_dashboards        = ("%%FLOWVIEWERDIR%%/SOC","%%FLOWVIEWERDIR%%/NetOps");
 #@dashboard_titles       = ();          # Set to empty if you have just the one nominal Dashboard
 @dashboard_titles        = ("Performance","SOC","NetOps"); # titles must be in the same order as the directories
 
-$flow_data_directory     = "/data/flows";
-$exporter_directory      = "/data/flows/all_routers";
-$flow_bin_directory      = "/usr/local/flow-tools/bin";
-$rrdtool_bin_directory   = "/usr/bin";
+$flow_data_directory     = "/var/db/flows";
+$exporter_directory      = "/var/db/flows/all_routers";
+$flow_bin_directory      = "%%PREFIX%%/bin";
+$rrdtool_bin_directory   = "%%PREFIX%%/bin";
 
 # SiLK parameters
 
@@ -207,7 +207,7 @@
 # Monitor parameters
  
 $actives_webpage    = "index.html";
-$log_directory      = "/var/www/cgi-bin/FlowViewer_4.5/logs";
+$log_directory      = "%%FLOWVIEWERDIR%%/logs";
 $log_collector_short= "Y";
 $log_collector_med  = "N";
 $log_collector_long = "N";
