--- programs/calc/gchemcalc.cc.orig	2009-05-03 13:55:23.000000000 -0400
+++ programs/calc/gchemcalc.cc	2009-05-03 13:55:34.000000000 -0400
@@ -736,7 +736,7 @@ int main (int argc, char *argv[])
 	App = new GChemCalc ();
 	
 	/* Initialize plugins manager */
-	go_plugins_init (NULL, NULL, NULL, NULL, TRUE, GO_PLUGIN_LOADER_MODULE_TYPE);
+	go_plugins_init (NULL, NULL, NULL, NULL, TRUE, GO_TYPE_PLUGIN_LOADER_MODULE);
 
 	GladeXML *xml =  glade_xml_new (GLADEDIR"/gchemcalc.glade", "gchemcalc", NULL);
 	App->window = GTK_WINDOW (glade_xml_get_widget (xml, "gchemcalc"));
