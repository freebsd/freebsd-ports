--- src/ui-popup.cc.orig	Wed Sep  1 11:05:08 2004
+++ src/ui-popup.cc	Tue Oct 12 14:15:09 2004
@@ -529,7 +529,7 @@
 					g_free (utf8_part);
 					utf8_text = buffer;
 				}
-				copy_part.clear();
+				copy_part.erase();
 			}
 			i+=2; 
 			if (i >= copy.size()) {
@@ -557,7 +557,7 @@
 				copy_part = _("* error *");
 				break;
 			}
-			copy_part.clear();
+			copy_part.erase();
 			while ((i < copy.size()) && (copy.substr(i,2) != "?="))
 				copy_part += copy[i++];
 			if (i >= copy.size()) {
