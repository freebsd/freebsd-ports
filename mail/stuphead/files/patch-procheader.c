--- src/procheader.c.orig	Tue Aug 17 14:26:04 2004
+++ src/procheader.c	Tue Aug 17 14:26:18 2004
@@ -439,6 +439,7 @@
 			msginfo->xface = g_strdup(hp);
 			break;
 		default:
+			break;
 		}
 	}
 	msginfo->inreplyto = reference;
