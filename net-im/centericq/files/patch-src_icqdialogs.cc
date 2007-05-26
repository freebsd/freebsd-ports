
$FreeBSD$

--- src/icqdialogs.cc.orig
+++ src/icqdialogs.cc
@@ -210,17 +210,17 @@
     switch(subj) {
 	case fsuser:
 	    db.setbar(new horizontalbar(conf.getcolor(cp_dialog_text), conf.getcolor(cp_dialog_selected),
-		_("lOad"), _("sAve"), _("cLear"), _("Change"), _("Search/Add"), 0));
+		_("lOad"), _("sAve"), _("cLear"), _("Change"), _("Search/Add"), 0L));
 	    break;
 
 	case fschannel:
 	    db.setbar(new horizontalbar(conf.getcolor(cp_dialog_text), conf.getcolor(cp_dialog_selected),
-		_("cLear"), _("Change"), _("Join/Create"), 0));
+		_("cLear"), _("Change"), _("Join/Create"), 0L));
 	    break;
 
 	case fsrss:
 	    db.setbar(new horizontalbar(conf.getcolor(cp_dialog_text), conf.getcolor(cp_dialog_selected),
-		_("cLear"), _("Change"), _("lInk"), 0));
+		_("cLear"), _("Change"), _("lInk"), 0L));
 	    break;
     }
 
@@ -894,7 +894,7 @@
     i = m.open();
     m.close();
 
-    if(i) f = (unsigned short) ((int) m.getref(i-1));
+    if(i) f = (unsigned short) ((intptr_t) m.getref(i-1));
 }
 
 void icqface::selectlanguage(unsigned short &f) {
@@ -946,7 +946,7 @@
     int i = m.open();
     m.close();
 
-    if(i) f = (imgender) ((int) m.getref(i-1));
+    if(i) f = (imgender) ((intptr_t) m.getref(i-1));
 }
 
 void icqface::selectagerange(ICQ2000::AgeRange &r) {
@@ -967,7 +967,7 @@
     int i = m.open();
     m.close();
 
-    if(i) r = (ICQ2000::AgeRange) ((int) m.getref(i-1));
+    if(i) r = (ICQ2000::AgeRange) ((intptr_t) m.getref(i-1));
 }
 
 bool icqface::edit(string &txt, const string &header) {
@@ -1256,7 +1256,7 @@
 
 	void *p;
 	finished = !db.open(n, b, &p);
-	i = (int) p;
+	i = (intptr_t) p;
 
 	if(!finished)
 	switch(b) {
@@ -1750,7 +1750,7 @@
 	    it = transfers.end();
 
 	    if(!db.gettree()->isnode(db.gettree()->getid(np-1)))
-		it = transfers.begin() + (int) db.getmenu()->getref(n-1);
+		it = transfers.begin() + (intptr_t) db.getmenu()->getref(n-1);
 
 	    switch(b) {
 		case 0:
