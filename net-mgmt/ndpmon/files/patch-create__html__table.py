--- create_html_table.py.orig	2010-12-18 23:33:50.000000000 +0100
+++ create_html_table.py	2010-12-18 23:35:24.000000000 +0100
@@ -1,4 +1,4 @@
-#!/usr/bin/python
+#!%%LOCALBASE%%/bin/python
 
 # takes in input the alerts via the pipe
 # write the alerts in a file in XML format
@@ -11,7 +11,7 @@
 from xml.dom import Node
 
 # The file in which we will write the alerts 
-alerts = "/var/local/ndpmon/alerts.xml"
+alerts = "%%PREFIX%%/var/ndpmon/alerts.xml"
 
 # The alert itself piped from NDPmon to this script
 lines = sys.stdin.readlines()
