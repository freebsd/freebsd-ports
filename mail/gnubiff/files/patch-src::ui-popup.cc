--- src/ui-popup.cc.bak	Sun Jan  9 14:22:10 2005
+++ src/ui-popup.cc	Sun Jan  9 14:22:31 2005
@@ -564,7 +564,7 @@
 					g_free (utf8_part);
 					utf8_text = buffer;
 				}
-				copy_part.clear();
+				copy_part.erase();
 			}
 			i+=2; 
 			if (i >= copy.size()) {
@@ -592,7 +592,7 @@
 				copy_part = _("* error *");
 				break;
 			}
-			copy_part.clear();
+			copy_part.erase();
 			while ((i < copy.size()) && (copy.substr(i,2) != "?="))
 				copy_part += copy[i++];
 			if (i >= copy.size()) {
