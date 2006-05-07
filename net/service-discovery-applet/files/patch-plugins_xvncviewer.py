--- plugins/xvncviewer.py.orig	Sat May  6 15:19:12 2006
+++ plugins/xvncviewer.py	Sat May  6 15:20:13 2006
@@ -19,11 +19,11 @@ class plugin_xvncviewer:
     def __init__(self):
         self.service_type = ["_rfb._tcp"]
         self.author = "Sebastien Estienne"
-        self.description = "Start a VNC connections with xvncviewer"
+        self.description = "Start a VNC connections with vncviewer"
 
     def connect(self, use_host_names, name, stype, hostname, address, port, txts):
-        print "connecting using xvncviewer"
-	cmdline = ["xvncviewer", "-xrm", "*passwordDialog:true", hostname ]
+        print "connecting using vncviewer"
+	cmdline = ["vncviewer", "-xrm", "*passwordDialog:true", hostname]
 	print cmdline
 	pid = subprocess.Popen(cmdline, close_fds=True).pid
 
