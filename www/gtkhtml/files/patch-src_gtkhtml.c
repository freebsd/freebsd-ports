--- src/gtkhtml.c.orig	Tue Nov  5 15:56:58 2002
+++ src/gtkhtml.c	Tue Dec 17 12:29:33 2002
@@ -1653,9 +1653,9 @@
 	be = swap ? be : !be;	
 
 	if (be)
-		return "ucs2-be";
+		return "ucs-2be";
 	else 
-		return "ucs2-le";
+		return "ucs-2le";
 	
 }
 
@@ -1733,7 +1733,7 @@
 			html_object_save (selection_object, state);
 			
 			d_s (g_warning ("text/html buffer = %s", buffer->str);)
-			selection_string = e_utf8_to_charset_string_sized ("ucs2", buffer->str, buffer->len);
+			selection_string = e_utf8_to_charset_string_sized ("ucs-2", buffer->str, buffer->len);
 			
 			if (selection_string)
 				gtk_selection_data_set (selection_data,
@@ -1897,11 +1897,11 @@
 					len  -= 2;
 					break;
 				default:
-					tocode = "ucs2";
+					tocode = ucs2_order(1);
 					break;
 				}
 				
-				utf8 = e_utf8_from_charset_string_sized ("ucs2",
+				utf8 = e_utf8_from_charset_string_sized (tocode,
 									 data,
 									 len);
 
