--- src/main.py.orig	Mon Dec  5 16:39:23 2005
+++ src/main.py	Mon Dec  5 16:41:07 2005
@@ -233,6 +233,17 @@
 
 class App:
 	def __init__(self):
+		# Check that there isn't already a PID file
+		if(os.path.isfile(utils.doPath(config.pid))):
+			print "PID file exists at that location. Please check for running PyMSNt and try again."
+			sys.exit(1)
+
+		# Create a PID file
+		pid = str(os.getpid())
+		pf = file(utils.doPath(config.pid),'w')
+		pf.write("%s\n" % pid);
+		pf.close()
+
 		jid = config.jid
 		if config.compjid: jid = config.compjid
 		self.c = component.buildServiceManager(jid, config.secret, "tcp:%s:%s" % (config.mainServer, config.port))
@@ -248,6 +259,7 @@
 	
 	def shuttingDown(self):
 		self.transportSvc.removeMe()
+		os.remove(utils.doPath(config.pid))
 		# Keep the transport running for another 3 seconds
 		def cb(ignored=None):
 			pass
