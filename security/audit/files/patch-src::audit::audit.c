--- src/audit/audit.c.orig	Thu Nov  4 07:24:04 2004
+++ src/audit/audit.c	Thu Nov  4 07:25:17 2004
@@ -143,6 +143,7 @@
 	case SIGABRT:
 		fatal(-1, "");
 	default:
+		break;
 	}
 	errno = old_errno;
 }
