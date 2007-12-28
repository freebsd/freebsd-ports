--- src/tuner.py	2007-12-12 04:40:38.000000000 +0100
+++ src/tuner.py.port	2007-12-22 22:50:00.000000000 +0100
@@ -296,7 +296,7 @@
     popen2.Popen4(browser+' '+url)
 
 def adultset():
-    try: adultconfig=open('/etc/tunapie.config')
+    try: adultconfig=open('%%LOCALBASE%%/etc/tunapie.config')
     except IOError: return 0
     setadult=adultconfig.readline()
     return int(setadult)
