Subject: OpenSSH Security Advisory: buffer.adv

This is the 2nd revision of the Advisory.

This document can be found at:  http://www.openssh.com/txt/buffer.adv

1. Versions affected:

        All versions of OpenSSH's sshd prior to 3.7.1 contain buffer
        management errors.  It is uncertain whether these errors are
        potentially exploitable, however, we prefer to see bugs
        fixed proactively.

        Other implementations sharing common origin may also have
        these issues.

2. Solution:

	Upgrade to OpenSSH 3.7.1 or apply the following patch.

===================================================================
Appendix A: patch for OpenSSH 3.6.1 and earlier

Index: buffer.c
===================================================================
RCS file: /cvs/src/usr.bin/ssh/buffer.c,v
retrieving revision 1.16
retrieving revision 1.18
diff -u -r1.16 -r1.18
--- buffer.c	26 Jun 2002 08:54:18 -0000	1.16
+++ buffer.c	16 Sep 2003 21:02:39 -0000	1.18
@@ -23,8 +23,11 @@
 void
 buffer_init(Buffer *buffer)
 {
-	buffer->alloc = 4096;
-	buffer->buf = xmalloc(buffer->alloc);
+	const u_int len = 4096;
+
+	buffer->alloc = 0;
+	buffer->buf = xmalloc(len);
+	buffer->alloc = len;
 	buffer->offset = 0;
 	buffer->end = 0;
 }
@@ -34,8 +37,11 @@
 void
 buffer_free(Buffer *buffer)
 {
-	memset(buffer->buf, 0, buffer->alloc);
-	xfree(buffer->buf);
+	if (buffer->alloc > 0) {
+		memset(buffer->buf, 0, buffer->alloc);
+		buffer->alloc = 0;
+		xfree(buffer->buf);
+	}
 }
 
 /*
@@ -69,6 +75,7 @@
 void *
 buffer_append_space(Buffer *buffer, u_int len)
 {
+	u_int newlen;
 	void *p;
 
 	if (len > 0x100000)
@@ -98,11 +105,13 @@
 		goto restart;
 	}
 	/* Increase the size of the buffer and retry. */
-	buffer->alloc += len + 32768;
-	if (buffer->alloc > 0xa00000)
+	
+	newlen = buffer->alloc + len + 32768;
+	if (newlen > 0xa00000)
 		fatal("buffer_append_space: alloc %u not supported",
-		    buffer->alloc);
-	buffer->buf = xrealloc(buffer->buf, buffer->alloc);
+		    newlen);
+	buffer->buf = xrealloc(buffer->buf, newlen);
+	buffer->alloc = newlen;
 	goto restart;
 	/* NOTREACHED */
 }
Index: channels.c
===================================================================
RCS file: /cvs/src/usr.bin/ssh/channels.c,v
retrieving revision 1.194
retrieving revision 1.195
diff -u -r1.194 -r1.195
--- channels.c	29 Aug 2003 10:04:36 -0000	1.194
+++ channels.c	16 Sep 2003 21:02:40 -0000	1.195
@@ -228,12 +228,13 @@
 	if (found == -1) {
 		/* There are no free slots.  Take last+1 slot and expand the array.  */
 		found = channels_alloc;
-		channels_alloc += 10;
 		if (channels_alloc > 10000)
 			fatal("channel_new: internal error: channels_alloc %d "
 			    "too big.", channels_alloc);
+		channels = xrealloc(channels,
+		    (channels_alloc + 10) * sizeof(Channel *));
+		channels_alloc += 10;
 		debug2("channel: expanding %d", channels_alloc);
-		channels = xrealloc(channels, channels_alloc * sizeof(Channel *));
 		for (i = found; i < channels_alloc; i++)
 			channels[i] = NULL;
 	}


