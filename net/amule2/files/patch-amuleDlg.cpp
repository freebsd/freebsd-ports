--- src/amuleDlg.cpp.orig	Tue May  3 20:37:09 2005
+++ src/amuleDlg.cpp	Tue May  3 20:39:53 2005
@@ -502,9 +502,9 @@
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
@@ -514,7 +514,8 @@
 		" 'All-Platform' p2p client based on eMule \n\n"
 		" Website: http://www.amule.org \n"
 		" Forum: http://forum.amule.org \n"
-		" FAQ: http://wiki.amule.org \n\n"
+		" FAQ: http://wiki.amule.org \n"
+		" FreeBSD port: http://contribs.martymac.com \n\n"
 		" Contact: admin@amule.org (administrative issues) \n"
 		" Copyright (C) 2003-2005 aMule Team \n");
 	if (is_safe_state) {
