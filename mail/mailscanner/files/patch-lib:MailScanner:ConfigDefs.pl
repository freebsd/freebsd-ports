--- ../MailScanner-4.21-9.orig/lib/MailScanner/ConfigDefs.pl	Sun May 18 13:24:36 2003
+++ lib/MailScanner/ConfigDefs.pl	Thu Jun 12 15:29:39 2003
@@ -153,9 +153,9 @@
 # Check the first word of these for file existence
 [Simple,File]
 pidfile			/var/run/MailScanner.pid
-spamassassinprefsfile	/opt/MailScanner/etc/spam.assassin.prefs.conf
-SpamListDefinitions	/opt/MailScanner/etc/spam.lists.conf
-VirusScannerDefinitions	/opt/MailScanner/etc/virus.scanners.conf
+spamassassinprefsfile	/usr/local/etc/MailScanner/spam.assassin.prefs.conf
+SpamListDefinitions	/usr/local/etc/MailScanner/spam.lists.conf
+VirusScannerDefinitions	/usr/local/etc/MailScanner/virus.scanners.conf
 
 # Check these to ensure they are just numbers
 [Simple,Number]
@@ -194,7 +194,7 @@
 SpamAssassinDefaultRulesDir	
 SpamAssassinInstallPrefix	
 SpamStarsCharacter	s
-TNEFExpander		/opt/MailScanner/bin/tnef --maxsize=100000000
+TNEFExpander		/usr/local/bin/tnef --maxsize=100000000
 VirusScanners		none  # Space-separated list
 
 #
@@ -239,23 +239,23 @@
 WarnSenders		1	no	0	yes	1
 
 [First,File]
-DeletedFilenameMessage	/opt/MailScanner/etc/reports/en/deleted.filename.message.txt
-DeletedVirusMessage	/opt/MailScanner/etc/reports/en/deleted.virus.message.txt
-DisinfectedReportText	/opt/MailScanner/etc/reports/en/disinfected.report.txt
-inlinehtmlsig		/opt/MailScanner/etc/reports/en/inline.sig.html
-inlinehtmlwarning	/opt/MailScanner/etc/reports/en/inline.warning.html
+DeletedFilenameMessage	/usr/local/share/MailScanner/reports/en/deleted.filename.message.txt
+DeletedVirusMessage	/usr/local/share/MailScanner/reports/en/deleted.virus.message.txt
+DisinfectedReportText	/usr/local/share/MailScanner/reports/en/disinfected.report.txt
+inlinehtmlsig		/usr/local/share/MailScanner/reports/en/inline.sig.html
+inlinehtmlwarning	/usr/local/share/MailScanner/reports/en/inline.warning.html
 inlinespamwarning	/etc/MailScanner/reports/en/inline.spam.warning.txt
-inlinetextsig		/opt/MailScanner/etc/reports/en/inline.sig.txt
-inlinetextwarning	/opt/MailScanner/etc/reports/en/inline.warning.txt
+inlinetextsig		/usr/local/share/MailScanner/reports/en/inline.sig.txt
+inlinetextwarning	/usr/local/share/MailScanner/reports/en/inline.warning.txt
 languagestrings		
-sendererrorreport 	/opt/MailScanner/etc/reports/en/sender.error.report.txt
-senderfilenamereport	/opt/MailScanner/etc/reports/en/sender.filename.report.txt
-SenderRBLSpamReport	/opt/MailScanner/etc/reports/en/sender.spam.rbl.report.txt
-SenderSASpamReport	/opt/MailScanner/etc/reports/en/sender.spam.sa.report.txt
-SenderBothSpamReport	/opt/MailScanner/etc/reports/en/sender.spam.report.txt
-sendervirusreport 	/opt/MailScanner/etc/reports/en/sender.virus.report.txt
-StoredFilenameMessage	/opt/MailScanner/etc/reports/en/stored.filename.message.txt
-StoredVirusMessage	/opt/MailScanner/etc/reports/en/stored.virus.message.txt
+sendererrorreport 	/usr/local/share/MailScanner/reports/en/sender.error.report.txt
+senderfilenamereport	/usr/local/share/MailScanner/reports/en/sender.filename.report.txt
+SenderRBLSpamReport	/usr/local/share/MailScanner/reports/en/sender.spam.rbl.report.txt
+SenderSASpamReport	/usr/local/share/MailScanner/reports/en/sender.spam.sa.report.txt
+SenderBothSpamReport	/usr/local/share/MailScanner/reports/en/sender.spam.report.txt
+sendervirusreport 	/usr/local/share/MailScanner/reports/en/sender.virus.report.txt
+StoredFilenameMessage	/usr/local/share/MailScanner/reports/en/stored.filename.message.txt
+StoredVirusMessage	/usr/local/share/MailScanner/reports/en/stored.virus.message.txt
 
 [First,Command]
 Sendmail		/usr/sbin/sendmail
@@ -311,7 +311,7 @@
 UseSpamAssassin		0	no	0	yes	1
 
 [All,File]
-#FilenameRules		/opt/MailScanner/etc/filename.rules.conf
+#FilenameRules		/usr/local/etc/MailScanner/filename.rules.conf
 FilenameRules		
 
 [All,Other]
