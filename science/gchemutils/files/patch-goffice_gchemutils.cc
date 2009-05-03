--- goffice/gchemutils.cc.orig	2009-05-03 13:54:25.000000000 -0400
+++ goffice/gchemutils.cc	2009-05-03 13:54:33.000000000 -0400
@@ -135,7 +135,7 @@ go_gchemutils_component_class_init (GOCo
 
 GSF_DYNAMIC_CLASS (GOGChemUtilsComponent, go_gchemutils_component,
 	go_gchemutils_component_class_init, go_gchemutils_component_init,
-	GO_COMPONENT_TYPE)
+	GO_TYPE_COMPONENT)
 
 /*************************************************************************************/
 
