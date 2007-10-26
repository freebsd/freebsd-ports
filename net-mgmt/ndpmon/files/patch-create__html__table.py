
$FreeBSD$

--- create_html_table.py.orig
+++ create_html_table.py
@@ -11,7 +11,7 @@
 from xml.dom import Node
 
 # The file in which we will write the alerts 
-alerts = "/var/local/ndpmon/alerts.xml"
+alerts = "%%PREFIX%%/var/ndpmon/alerts.xml"
 
 # The alert itself piped from NDPmon to this script
 lines = sys.stdin.readlines()
