--- fontforge/fontinfo.c.orig	Wed Jan 11 20:00:54 2006
+++ fontforge/fontinfo.c	Tue Jan 24 12:55:39 2006
@@ -5311,6 +5311,7 @@
 		 (sf->xuid!=NULL && uc_strcmp(txt,sf->xuid)==0) ||
 		 ttfuniqueidmatch(sf,d)) ) {
 	    char *buts[4];
+	    int ans;
 	    buts[0] = _("Change");
 	    buts[1] = _("Retain");
 #if defined(FONTFORGE_CONFIG_GDRAW)
@@ -5319,7 +5320,7 @@
 	    buts[2] = GTK_STOCK_CANCEL;
 #endif
 	    buts[3] = NULL;
-	    int ans = gwwv_ask(_("Change UniqueID?"),(const char **) buts,0,2,_("You have changed this font's name without changing the UniqueID (or XUID).\nThis is probably not a good idea, would you like me to\ngenerate a random new value?"));
+	    ans = gwwv_ask(_("Change UniqueID?"),(const char **) buts,0,2,_("You have changed this font's name without changing the UniqueID (or XUID).\nThis is probably not a good idea, would you like me to\ngenerate a random new value?"));
 	    if ( ans==2 ) {
 		GDrawSetCursor(gw,ct_pointer);
 return(true);
