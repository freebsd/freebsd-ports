--- src/tuner.py	Sat Sep 30 01:02:41 2006
+++ src/tuner.py.port	Wed Oct 18 14:19:58 2006
@@ -298,7 +298,7 @@
     return process
 
 def adultset():
-    try: adultconfig=open('/etc/tunapie.config')
+    try: adultconfig=open('%%PREFIX%%/etc/tunapie.config')
     except IOError: return 0
     setadult=adultconfig.readline()
     return int(setadult)
