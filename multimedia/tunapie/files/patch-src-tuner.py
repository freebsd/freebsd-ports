$FreeBSD$
--- src/tuner.py	Sun Apr 15 13:04:12 2007
+++ src/tuner.py.port	Wed Apr 18 23:23:51 2007
@@ -296,7 +296,7 @@
     popen2.Popen4(browser+' '+url)
 
 def adultset():
-    try: adultconfig=open('/etc/tunapie.config')
+    try: adultconfig=open('%%LOCALBASE%%/etc/tunapie.config')
     except IOError: return 0
     setadult=adultconfig.readline()
     return int(setadult)
