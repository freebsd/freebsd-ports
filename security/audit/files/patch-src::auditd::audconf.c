--- src/auditd/audconf.c.orig	Thu Nov  4 07:25:36 2004
+++ src/auditd/audconf.c	Thu Nov  4 07:25:45 2004
@@ -295,6 +295,7 @@
 		strlcpy(options->resmodule, value, sizeof(options->resmodule));
 		return (0);
 	default:
+		break;
 	}
 
 	errno = EINVAL;
