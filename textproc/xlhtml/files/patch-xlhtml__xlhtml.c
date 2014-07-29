
$FreeBSD$

--- xlhtml/xlhtml.c	2002/02/27 18:10:01	1.1
+++ xlhtml/xlhtml.c	2002/02/27 18:12:58
@@ -746,8 +746,13 @@
 					ws_array[i]->ws_title.str, ws_array[i]->biggest_row, ws_array[i]->biggest_col);
 			}
 		}
-		else if (Xtract)
+		else if (Xtract) {
+			if (xr2 == HARD_MAX_ROWS)
+				xr2 = ws_array[xp]->biggest_row;
+			if (xc2 == HARD_MAX_COLS)
+				xc2 = ws_array[xp]->biggest_col;
 			OutputPartialTableAscii();
+		}
 	}
 	else
 	{
