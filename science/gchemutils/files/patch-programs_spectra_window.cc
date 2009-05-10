--- programs/spectra/window.cc.orig	2009-05-10 15:08:58.000000000 -0400
+++ programs/spectra/window.cc	2009-05-10 15:09:03.000000000 -0400
@@ -320,7 +320,7 @@ static void on_get_data (GtkClipboard *c
 			go_locale_untranslated_booleans ();
 		
 			xout = gsf_xml_out_new (output);
-			gog_object_write_xml_sax (GOG_OBJECT (graph), xout);
+			gog_object_write_xml_sax (GOG_OBJECT (graph), xout, NULL);
 			g_object_unref (xout);
 		
 			/* go_setlocale restores bools to locale translation */
