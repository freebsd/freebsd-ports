--- xymonnet/httpresult.c.orig	2015-11-23 19:40:49 UTC
+++ xymonnet/httpresult.c
@@ -64,10 +64,10 @@ static int statuscolor(testedhost_t *h, 
 		break;
 	  default:
 		/* Unknown or custom status */
-		result = (result < 100) ? (h->dialup ? COL_CLEAR : COL_RED) :
-			 (result < 200) ? COL_YELLOW :
-			 (result < 300) ? COL_GREEN  :
-			 (result < 400) ? COL_YELLOW :
+		result = (status < 100) ? (h->dialup ? COL_CLEAR : COL_RED) :
+			 (status < 200) ? COL_YELLOW :
+			 (status < 300) ? COL_GREEN  :
+			 (status < 400) ? COL_YELLOW :
 			 COL_RED;
 		break;
 	}
