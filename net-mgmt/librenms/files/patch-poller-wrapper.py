--- poller-wrapper.py.orig	2020-07-20 20:50:23 UTC
+++ poller-wrapper.py
@@ -27,6 +27,8 @@
 
 import LibreNMS.library as LNMS
 
+os.environ['PATH'] += ':/usr/local/sbin:/usr/local/bin'
+
 try:
 
     import json
