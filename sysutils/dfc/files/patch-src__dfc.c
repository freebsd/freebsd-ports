--- ./src/dfc.c.orig	2012-04-03 23:38:18.000000000 +0200
+++ ./src/dfc.c	2012-04-13 00:05:00.488294758 +0200
@@ -713,10 +713,12 @@
                if (strlcat(buffer, ",acls", bufsize) >= bufsize)
                        goto truncated;
 			/* NOTREACHED */
+#if __FreeBSD__version > 800000
        if (flags & MNT_NFS4ACLS)
                if (strlcat(buffer, ",nfsv4acls", bufsize) >= bufsize)
 		       goto truncated;
 			/* NOTREACHED */
+#endif
 
        return buffer;
        /* NOTREACHED */
