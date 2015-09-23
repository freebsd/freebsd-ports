Index: xymonnet/httpresult.c
===================================================================
--- xymonnet/httpresult.c	(revision 7670)
+++ xymonnet/httpresult.c	(working copy)
@@ -36,13 +36,26 @@
 		result = (h->dialup ? COL_CLEAR : COL_RED);
 		break;
 	  case 100: /* Continue - should be ok */
-	  case 200: case 201: case 202: case 203: case 204: case 205: case 206:
-	  case 301: case 302: case 303: case 307:
-	  case 401: case 403: 		/* Is "Forbidden" an OK status ? */
+	  case 200:
+	  case 201:
+	  case 202:
+	  case 203:
+	  case 204:
+	  case 205:
+	  case 206:
+	  case 301:
+	  case 302:
+	  case 303:
+	  case 307:
 		result = COL_GREEN;
 		break;
-	  case 400: case 404: case 405: case 406:
-		result = COL_RED;	/* Trouble getting page */
+	  case 400:
+	  case 401:
+	  case 403:  /* Trouble getting page */
+	  case 404:
+	  case 405:
+	  case 406:
+		result = COL_RED;
 		break;
 	  case 500:
 	  case 501:
