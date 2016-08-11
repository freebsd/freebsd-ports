--- xlhtml/xlhtml.c.orig	2002-04-11 03:25:17 UTC
+++ xlhtml/xlhtml.c
@@ -616,8 +616,13 @@ void scan_file(COLEDIRENT *cde, void *_i
 					ws_array[i]->biggest_row, ws_array[i]->biggest_col);
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
