--- prim.c.orig	Mon Feb 24 12:45:40 1992
+++ prim.c	Sat May 20 01:42:18 2000
@@ -110,7 +110,7 @@
 			 *    but we don't yet know if that will happen. }}
 			 */
 			if (top_scroll == 2)
-				clear();
+				clearscr();
 			home();
 			force = 1;
 		} else
@@ -132,7 +132,7 @@
 			if (top_scroll)
 			{
 				if (top_scroll == 2)
-					clear();
+					clearscr();
 				home();
 			} else if (!first_time)
 			{
@@ -352,7 +352,7 @@
 	}
 	lastmark();
 	pos = ch_tell();
-	clear();
+	clearscr();
 	pos_clear();
 	add_back_pos(pos);
 	back(sc_height - 1, pos, 0, 0);
@@ -503,7 +503,7 @@
 			 * More than a screenful back.
 			 */
 			lastmark();
-			clear();
+			clearscr();
 			pos_clear();
 			add_back_pos(npos);
 		}
