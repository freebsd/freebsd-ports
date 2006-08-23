--- src/icqdialogs.cc	Fri Aug 18 04:42:04 2006
+++ src/icqdialogs.cc.new	Fri Aug 18 04:44:07 2006
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
 
