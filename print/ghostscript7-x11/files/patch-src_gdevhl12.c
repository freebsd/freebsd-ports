--- src/gdevhl12.c.orig	2002-09-22 23:15:05 UTC
+++ src/gdevhl12.c
@@ -640,7 +640,7 @@ hl1250_print_page_copies(gx_device_print
 	case TRAY_MANUAL:
 	    tray_pcl = "\033&l2H";
 	    break;
-	default:
+	default: ;
     }
     if (pdev->PageCount == 0) {
 	/* initialize printer */
