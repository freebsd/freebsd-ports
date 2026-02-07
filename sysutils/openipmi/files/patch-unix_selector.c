--- unix/selector.c.orig	2020-10-24 10:59:38 UTC
+++ unix/selector.c
@@ -1030,7 +1030,10 @@ process_fds(struct selector_s	    *sel,
 		  &tmp_except_set,
 		  &ts, &sigmask);
     if (err < 0) {
-	if (errno == EBADF || errno == EBADFD)
+	/* We do not have EBADFD, as it is Solaris and Linux specific;
+	 * if (errno == EBADF || errno == EBADFD)
+	 */
+	if (errno == EBADF)
 	    /* We raced, just retry it. */
 	    goto retry;
 	goto out;
