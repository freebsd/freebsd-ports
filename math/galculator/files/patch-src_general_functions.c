$FreeBSD$
--- src/general_functions.c.orig	Mon Jun 23 21:34:24 2003
+++ src/general_functions.c	Thu Jun 26 00:23:54 2003
@@ -512,14 +512,6 @@ void set_object_data (GladeXML *xml)
 		{"button_parclose", ')'},\
 		{NULL}\
 	};
-	
-	while (operation_map[counter].button_name != NULL) {
-		g_object_set_data (G_OBJECT (glade_xml_get_widget (xml, 
-			operation_map[counter].button_name)),
-			"operation", GINT_TO_POINTER(operation_map[counter].operation));
-		counter++;
-	}
-	counter = 0;
 
 	s_gfunc_map gfunc_map[] = {\
 		{"button_sign", display_result_toggle_sign},\
@@ -530,14 +522,6 @@ void set_object_data (GladeXML *xml)
 		{NULL}\
 	};
 	
-	while (gfunc_map[counter].button_name != NULL) {
-		g_object_set_data (G_OBJECT (glade_xml_get_widget (xml, 
-			gfunc_map[counter].button_name)),
-			"func", gfunc_map[counter].func);
-		counter++;
-	};
-	counter = 0;
-	
 	s_function_map function_map[] = {\
 		{"button_sin", {sin, asin, sinh, sin}, TRUE},\
 		{"button_cos", {cos, acos, cosh, cos}, TRUE},\
@@ -551,6 +535,22 @@ void set_object_data (GladeXML *xml)
 		{"button_cmp", {cmp, cmp, cmp, cmp}, FALSE},\
 		{NULL}\
 	};
+	
+	while (operation_map[counter].button_name != NULL) {
+		g_object_set_data (G_OBJECT (glade_xml_get_widget (xml, 
+			operation_map[counter].button_name)),
+			"operation", GINT_TO_POINTER(operation_map[counter].operation));
+		counter++;
+	}
+	counter = 0;
+	
+	while (gfunc_map[counter].button_name != NULL) {
+		g_object_set_data (G_OBJECT (glade_xml_get_widget (xml, 
+			gfunc_map[counter].button_name)),
+			"func", gfunc_map[counter].func);
+		counter++;
+	};
+	counter = 0;
 	
 	while (function_map[counter].button_name != NULL) {
 		func = (void *) malloc (sizeof (function_map[counter].func));
