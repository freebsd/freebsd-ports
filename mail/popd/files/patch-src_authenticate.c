
$FreeBSD$

--- src/authenticate.c.orig	Sun Aug 22 16:49:10 2004
+++ src/authenticate.c	Sun Aug 22 16:49:28 2004
@@ -231,6 +231,7 @@
 		case RAD_ACCESS_REJECT:
 		case RAD_ACCESS_CHALLENGE:
 			/* Fall through */
+		break;
 	}
 	rad_close(authreq);
 	return(FALSE);
