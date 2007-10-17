--- src/audit/audit.c.orig	2001-10-06 01:14:58.000000000 +0200
+++ src/audit/audit.c	2007-10-17 09:41:34.000000000 +0200
@@ -147,6 +147,7 @@
 	case SIGABRT:
 		fatal(-1, "");
 	default:
+		break;
 	}
 	errno = old_errno;
 }
