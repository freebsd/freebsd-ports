--- src/main.py.orig	2008-02-08 11:55:07.000000000 -0200
+++ src/main.py	2008-02-08 12:43:07.000000000 -0200
@@ -379,7 +379,10 @@
 	# Set SIGHUP to reload the config file & close & open debug file
 	signal.signal(signal.SIGHUP, SIGHUPstuff)
 	# Load some scripts for PID and daemonising
-	from twisted.scripts import _twistd_unix as twistd
+	try:
+		from twisted.scripts import _twistd_unix as twistd
+	except:
+		from twisted.scripts import twistd
 
 
 def main():
