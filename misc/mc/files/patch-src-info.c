--- src/info.c.orig	Wed Jan 29 04:58:22 2003
+++ src/info.c	Tue Jun 15 03:15:09 2004
@@ -123,7 +123,7 @@
 	    size_trunc_len (buffer1, 5, myfs_stats.avail, 1);
 	    size_trunc_len (buffer2, 5, myfs_stats.total, 1);
 	    printw (_("Free space: %s (%d%%) of %s"), buffer1, myfs_stats.total ?
-		    100 * myfs_stats.avail / myfs_stats.total : 0, buffer2);
+		    (int) (100.0 * myfs_stats.avail / myfs_stats.total) : 0, buffer2);
 	} else
 	    addstr (_("No space information"));
 
@@ -170,7 +170,7 @@
 	    printw (_("Size:      %s"), buffer);
 #ifdef HAVE_ST_BLOCKS
 	    printw ((buf.st_blocks==1) ?
-		_(" (%d block)") : _(" (%d blocks)"), buf.st_blocks);
+		_(" (%ld block)") : _(" (%ld blocks)"), (long) buf.st_blocks);
 #endif
 	}
 	
