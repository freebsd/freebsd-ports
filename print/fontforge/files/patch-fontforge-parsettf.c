--- fontforge/parsettf.c.orig	Sun Jan 15 00:40:17 2006
+++ fontforge/parsettf.c	Tue Jan 24 13:04:32 2006
@@ -4277,18 +4277,19 @@
     if ( !info->onlystrikes &&
 	    info->glyphlocations_start!=0 && info->glyph_start!=0 &&
 	    info->cff_start!=0 ) {
+	int choice;
 	char *buts[4];
 	buts[0] = _("TTF 'glyf'");
 	buts[1] = _("OTF 'CFF '");
 	buts[3] = NULL;
 #if defined(FONTFORGE_CONFIG_GDRAW)
 	buts[2] = _("_Cancel");
-	int choice = gwwv_ask(_("Pick a font, any font..."),(const char **) buts,0,2,_("This font contains both a TrueType 'glyf' table and an OpenType 'CFF ' table. FontForge can only deal with one at a time, please pick which one you want to use"));
+	choice = gwwv_ask(_("Pick a font, any font..."),(const char **) buts,0,2,_("This font contains both a TrueType 'glyf' table and an OpenType 'CFF ' table. FontForge can only deal with one at a time, please pick which one you want to use"));
 #elif defined(FONTFORGE_CONFIG_GTK)
 	buts[2] = GTK_STOCK_CANCEL;
-	int choice = gwwv_ask(_("Pick a font, any font..."),(const char **) buts,0,2,_("This font contains both a TrueType 'glyf' table and an OpenType 'CFF ' table. FontForge can only deal with one at a time, please pick which one you want to use"));
+	choice = gwwv_ask(_("Pick a font, any font..."),(const char **) buts,0,2,_("This font contains both a TrueType 'glyf' table and an OpenType 'CFF ' table. FontForge can only deal with one at a time, please pick which one you want to use"));
 #else
-	int choice = 0;
+	choice = 0;
 #endif
 	if ( choice==2 ) {
 	    setlocale(LC_NUMERIC,oldloc);
