--- src/gdevhl12.c.orig	Sun Aug  1 13:39:19 2004
+++ src/gdevhl12.c	Sun Aug  1 13:40:07 2004
@@ -640,7 +640,7 @@
 	case TRAY_MANUAL:
 	    tray_pcl = "\033&l2H";
 	    break;
-	default:
+	default: ;
     }
     if (pdev->PageCount == 0) {
 	/* initialize printer */
