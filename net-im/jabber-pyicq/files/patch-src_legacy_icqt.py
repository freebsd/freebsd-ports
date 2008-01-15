--- src/legacy/icqt.py.orig	2008-01-09 04:58:42.000000000 +0100
+++ src/legacy/icqt.py	2008-01-13 08:06:51.411126927 +0100
@@ -327,7 +327,8 @@
 					status = msg[0] + ": " + status
 
 			status = status.decode(charset, 'replace')
-			LogEvent(INFO, self.session.jabberID, "Away (%s, %s) message %s" % (charset, msg[0], status))
+			utfmsg = unicode(msg[0], errors='replace')
+			LogEvent(INFO, self.session.jabberID, "Away (%s, %s) message %s" % (charset, utfmsg[0], status))
 
 		if status == "Away" or status=="I am currently away from the computer." or status=="I am away from my computer right now.":
 			status = ""
