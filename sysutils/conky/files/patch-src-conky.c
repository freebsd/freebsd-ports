--- src/conky.c.orig	Sat Dec 31 17:36:16 2005
+++ src/conky.c	Sat Jan  7 14:13:47 2006
@@ -4853,6 +4853,7 @@
 				CONF_ERR;
 		}
 		CONF("xftfont") {
+			if (use_xft)
 #else
 		CONF("use_xft") {
 			if (string_to_bool(value))
@@ -4866,12 +4867,10 @@
 		}
 		CONF("font") {
 #endif
-			if (use_xft) {
-				if (value) {
-					set_first_font(value);
-				} else
-					CONF_ERR;
-			}
+			if (value) {
+				set_first_font(value);
+			} else
+				CONF_ERR;
 		}
 		CONF("gap_x") {
 			if (value)
