--- fail2ban/client/fail2banreader.py.orig	2014-04-03 15:33:44.000000000 +0200
+++ fail2ban/client/fail2banreader.py	2014-04-03 15:34:00.000000000 +0200
@@ -45,7 +45,7 @@
 		return ConfigReader.getOptions(self, "Definition", opts)
 	
 	def getOptions(self):
-		opts = [["int", "loglevel", "INFO" ],
+		opts = [["string", "loglevel", "INFO" ],
 				["string", "logtarget", "STDERR"],
 				["string", "dbfile", "/var/lib/fail2ban/fail2ban.sqlite3"],
 				["int", "dbpurgeage", 86400]]
