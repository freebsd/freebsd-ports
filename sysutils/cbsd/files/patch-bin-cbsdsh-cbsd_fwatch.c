--- bin/cbsdsh/cbsd_fwatch.c.orig	2015-02-05 17:33:24.019144000 +0300
+++ bin/cbsdsh/cbsd_fwatch.c	2015-02-05 16:57:53.000000000 +0300
@@ -95,7 +95,6 @@
 		return 1;
 	}
 
-
 	if ((fd = open(watchfile, O_RDONLY)) == -1) {
 		out2fmt_flush("Cannot open: %s\n", watchfile);
 		ckfree(watchfile);
@@ -117,6 +116,7 @@
 		out2fmt_flush("kevent\n");
 		close(fd);
 		ckfree(watchfile);
+		close(kq);
 		return 1;
 	}
 
@@ -134,9 +134,12 @@
 		out2fmt_flush("kevent\n");
 		close(fd);
 		ckfree(watchfile);
+		close(kq);
 		return 1;
 	}
 
+	close(kq);
+
 	if (nev != 0) {
 		if (ev.fflags & NOTE_DELETE) {
 			out2fmt_flush("deleted\n");
@@ -173,5 +176,7 @@
 			ev.fflags &= ~NOTE_REVOKE;
 		}
 	}
+	
+	ckfree(watchfile);
 	return 0;
 }
