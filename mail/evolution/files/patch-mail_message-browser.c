--- mail/message-browser.c.orig	Mon Aug  2 13:11:44 2004
+++ mail/message-browser.c	Mon Aug  2 13:11:51 2004
@@ -344,7 +344,7 @@
 	case GDK_Escape:
 		message_browser_close (NULL, mb, NULL);
 		return TRUE;	
-	default:
+	default:;
 	}
 	
 	return FALSE;
