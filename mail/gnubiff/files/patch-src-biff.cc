--- src/biff.cc.orig	Fri Sep  3 20:19:11 2004
+++ src/biff.cc	Tue Oct 12 14:56:23 2004
@@ -68,14 +68,14 @@
 								 GError **error)
 	{
 		BIFF(data)->xml_start_element (context, element_name, attribute_names, attribute_values, error);
-	};
+	}
 
 	void BIFF_xml_error (GMarkupParseContext *context,
 						 GError *error,
 						 gpointer data)
 	{
 		BIFF(data)->xml_error (context, error);
-	};
+	}
 }
 
 
