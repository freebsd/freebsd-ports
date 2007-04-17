--- src/tuner.py	Wed Apr 11 00:20:17 2007
+++ src/tuner.py.port	Tue Apr 17 14:57:55 2007
@@ -14,7 +14,7 @@
 #along with this program; if not, write to the Free Software
 #Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 #
-#Version 0.3.19 08/04/07
+#Version 0.3.20 11/04/07
 
 import urllib
 import popen2
@@ -29,9 +29,12 @@
 import time
 
 def pkill(program):
+    flag=""
     rip = program
     me = commands.getoutput("whoami")
-    p = commands.getoutput("ps -u %s -o comm -o pid" % me)
+    if sys.platform.find("linux")==-1:
+        flag="-"
+    p = commands.getoutput("ps "+flag+"U "+me+" "+flag+"o pid "+flag+"o command")
     ids = p.split("\n")
     found=0
     firstrun=1
@@ -44,10 +47,13 @@
             else:
                 found=1
             firstrun=0
-        regex = re.compile(r'(\d+).*',re.I)
-        id = regex.sub(r'\1', id)
+        id=id.split(" ")
+        try: 
+            id=str(int(id[0]))
+        except:
+            id=str(int(id[1]))
         commands.getoutput("kill -15 %s" % id)
-        if commands.getoutput("ps -u %s -o fname -o pid" % me).find(id) > -1:
+        if commands.getoutput("ps "+flag+"U "+me+" "+flag+"o pid "+flag+"o command").find(id) > -1:
             commands.getoutput("kill -9 %s" % id)
     return found
 
@@ -290,7 +296,7 @@
     popen2.Popen4(browser+' '+url)
 
 def adultset():
-    try: adultconfig=open('/etc/tunapie.config')
+    try: adultconfig=open('%%LOCALBASE%%/etc/tunapie.config')
     except IOError: return 0
     setadult=adultconfig.readline()
     return int(setadult)
