--- cfs_fh.c.orig	Mon Aug 27 01:47:52 2001
+++ cfs_fh.c	Mon Aug 27 01:48:41 2001
@@ -177,6 +177,13 @@
 		perror("write");
 		return -1;
 	}
+	/* due to the way the file is padded we may actually have to
+	   truncate it here. This happens when the write is at the end of
+	   the file, is shorter than CFSBLOCK and brings the file to a length
+	   which is evenly dividable by CFSBLOCK */
+	if (offset+len > dtov(sb.st_size) && vtod(offset+len) < sb.st_size) {
+	  ftruncate(fd, vtod(offset+len));
+	}
 	/* iolen may contain CFSBLOCK extra chars */
 	return(dtov(iolen)-fronterr);
 }
