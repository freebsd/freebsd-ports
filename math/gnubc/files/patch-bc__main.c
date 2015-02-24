--- bc/main.c.orig	2006-12-01 14:30:52.000000000 -0800
+++ bc/main.c	2006-12-01 14:31:13.000000000 -0800
@@ -127,6 +127,9 @@
 	  warn_not_std = TRUE;
 	  break;
 
+	case 0:
+	  break;
+
 	default:
 	  usage(argv[0]);
 	  exit (1);
