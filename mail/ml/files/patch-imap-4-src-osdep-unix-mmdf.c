--- ../imap-4/src/osdep/unix/mmdf.c.orig	Tue Mar 31 13:07:25 1998
+++ ../imap-4/src/osdep/unix/mmdf.c	Sat Aug 20 00:17:25 2005
@@ -869,7 +869,7 @@
 				/* length of internal + message headers */
     iov[j].iov_len = (m->header + m->headersize) - m->internal;
 				/* suppress extra newline if present */
-    if ((iov[j].iov_base)[iov[j].iov_len - 2] == '\n') iov[j++].iov_len--;
+    if (((char *)iov[j].iov_base)[iov[j].iov_len - 2] == '\n') iov[j++].iov_len--;
     else j++;			/* unlikely but... */
 				/* status */
     iov[j].iov_base = status;
@@ -1727,7 +1727,7 @@
 				/* length of internal + message headers */
       iov[j].iov_len = (m->header + m->headersize) - m->internal;
 				/* suppress extra newline if present */
-      if ((iov[j].iov_base)[iov[j].iov_len - 2] == '\n') iov[j++].iov_len--;
+      if (((char *)iov[j].iov_base)[iov[j].iov_len - 2] == '\n') iov[j++].iov_len--;
       else j++;			/* unlikely but... */
 				/* status */
       iov[j].iov_base = LOCAL->buf;
