--- psspecial.c.orig	Tue May 29 20:02:33 2001
+++ psspecial.c	Tue May 29 20:03:09 2001
@@ -116,7 +116,7 @@
 	      p -> yscale = atof(val)/100.0;
 	      break;
 	    case ANGLE:
-	      p -> rotate = atof(val)/100.0;
+	      p -> rotate = atof(val) * M_PI / 180.0;
 	      break;
 	    case LLX:
 	      p -> user_bbox = 1;
