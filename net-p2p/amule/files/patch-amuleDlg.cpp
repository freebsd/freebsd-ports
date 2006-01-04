--- src/amuleDlg.cpp.orig	Sun Jan  1 06:17:25 2006
+++ src/amuleDlg.cpp	Tue Jan  3 19:12:04 2006
@@ -413,9 +413,9 @@
 {
 	wxString msg = wxT(" ");
 #ifdef CLIENT_GUI
-	msg << _("aMule remote control ") << wxT(VERSION);
+	msg << _("aMule remote control ") << wxT(VERSION) << wxT(" for FreeBSD");
 #else
-	msg << wxT("aMule ") << wxT(VERSION);
+	msg << wxT("aMule ") << wxT(VERSION) << wxT(" for FreeBSD");
 #endif
 	msg << wxT(" ");
 #ifdef CVSDATE
@@ -425,7 +425,8 @@
 		" 'All-Platform' p2p client based on eMule \n\n"
 		" Website: http://www.amule.org \n"
 		" Forum: http://forum.amule.org \n"
-		" FAQ: http://wiki.amule.org \n\n"
+		" FAQ: http://wiki.amule.org \n"
+		" FreeBSD port: http://contribs.martymac.com \n\n"
 		" Contact: admin@amule.org (administrative issues) \n"
 		" Copyright (C) 2003-2006 aMule Team \n\n"
 		" Part of aMule is based on \n"
