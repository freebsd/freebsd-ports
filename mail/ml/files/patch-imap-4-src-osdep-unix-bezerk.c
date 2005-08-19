--- ../imap-4/src/osdep/unix/bezerk.c.orig	Tue Mar 31 13:07:23 1998
+++ ../imap-4/src/osdep/unix/bezerk.c	Sat Aug 20 00:11:13 2005
@@ -896,7 +896,7 @@
 				/* length of internal + message headers */
     iov[j].iov_len = (m->header + m->headersize) - m->internal;
 				/* suppress extra newline if present */
-    if ((iov[j].iov_base)[iov[j].iov_len - 2] == '\n') iov[j++].iov_len--;
+    if (((char *)iov[j].iov_base)[iov[j].iov_len - 2] == '\n') iov[j++].iov_len--;
     else j++;			/* unlikely but... */
 				/* status */
     iov[j].iov_base = status;
@@ -1775,7 +1775,7 @@
 				/* length of internal + message headers */
       iov[j].iov_len = (m->header + m->headersize) - m->internal;
 				/* suppress extra newline if present */
-      if ((iov[j].iov_base)[iov[j].iov_len - 2] == '\n') iov[j++].iov_len--;
+      if (((char *)iov[j].iov_base)[iov[j].iov_len - 2] == '\n') iov[j++].iov_len--;
       else j++;			/* unlikely but... */
 				/* status */
       iov[j].iov_base = LOCAL->buf;
