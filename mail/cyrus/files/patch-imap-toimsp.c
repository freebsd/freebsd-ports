--- imap/toimsp.c.orig	Tue Oct 28 05:27:12 2003
+++ imap/toimsp.c	Tue Oct 28 05:27:25 2003
@@ -129,7 +129,7 @@
 		break;
 
 	    default:
-		abort("Internal error: unrecognized toimsp type", EC_SOFTWARE);
+		abort();
 	    }
 	}
     }
@@ -141,7 +141,7 @@
     iov[num_iov++].iov_len = 1;
 
     if (num_iov > VECSIZE) {
-	abort("Internal error: toimsp arg list overflow", EC_SOFTWARE);
+	abort();
     }
 
     (void) retry_writev(fd, iov, num_iov);
