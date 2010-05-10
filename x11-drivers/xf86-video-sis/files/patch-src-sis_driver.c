--- src/sis_driver.c.orig	2010-05-10 09:36:17.000000000 -0500
+++ src/sis_driver.c	2010-05-10 09:36:23.000000000 -0500
@@ -4099,6 +4099,8 @@
 	     case SIS_315H:
 	     case SIS_330:
 	     case SIS_340:
+	     case SIS_650:
+	     case SIS_760:
 	     case XGI_40:     readpci = TRUE;
 			      break;
 	     case XGI_20:     readpci = TRUE;
