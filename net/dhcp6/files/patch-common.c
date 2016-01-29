--- common.c.orig	2016-01-28 11:27:18 UTC
+++ common.c
@@ -3202,6 +3202,9 @@ setloglevel(debuglevel)
 		case 1:
 			setlogmask(LOG_UPTO(LOG_INFO));
 			break;
+		case 2:
+			setlogmask(LOG_UPTO(LOG_DEBUG));
+			break;
 		}
 	}
 }
