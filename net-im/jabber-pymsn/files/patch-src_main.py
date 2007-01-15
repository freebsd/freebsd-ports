--- src/main.py.orig	Wed Oct 18 01:40:55 2006
+++ src/main.py	Sun Jan 14 19:47:46 2007
@@ -390,7 +390,10 @@
 	# Set SIGHUP to reload the config file & close & open debug file
 	signal.signal(signal.SIGHUP, SIGHUPstuff)
 	# Load some scripts for PID and daemonising
-	from twisted.scripts import twistd
+	try:
+		from twisted.scripts import _twistd_unix as twistd
+	except:
+		from twisted.scripts import twistd
 
 
 def main():
