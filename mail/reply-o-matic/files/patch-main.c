--- main.c.orig	Thu May 13 18:44:13 2004
+++ main.c	Thu May 13 18:44:46 2004
@@ -929,7 +929,7 @@
 		case -1: 
 			 diedie(2);
 			 break;
-		default:
+/*		default: */
 	}
 	if ( forwardto[0] != 0 ) {
 		pipe(dfd);
@@ -966,7 +966,7 @@
 			case -1: 
 				 diedie(2);
 				 break;
-			default:
+/*			default: */
 		}
 	}
 
