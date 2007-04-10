--- src/tuner.py	Mon Apr  9 00:35:15 2007
+++ src/tuner.py.port	Mon Apr  9 16:33:50 2007
@@ -290,7 +290,7 @@
     popen2.Popen4(browser+' '+url)
 
 def adultset():
-    try: adultconfig=open('/etc/tunapie.config')
+    try: adultconfig=open('%%LOCALBASE%%/etc/tunapie.config')
     except IOError: return 0
     setadult=adultconfig.readline()
     return int(setadult)
