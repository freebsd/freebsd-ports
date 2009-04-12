--- src/cats/sql.c.orig	2008-11-11 09:33:46.000000000 -0500
+++ src/cats/sql.c	2009-04-11 20:35:41.171024520 -0400
@@ -759,7 +759,7 @@
    if (mdb->lock.valid == RWLOCK_VALID) { 
       fprintf(fp, "\tRWLOCK=%p w_active=%i w_wait=%i\n", &mdb->lock, mdb->lock.w_active, mdb->lock.w_wait);
 #ifndef HAVE_WIN32
-      fprintf(fp, "\t\tthreadid=0x%x mutex=%p\n", (int)mdb->lock.writer_id, &mdb->lock.mutex);
+      fprintf(fp, "\t\tthreadid=0x%lx mutex=%p\n", (long)mdb->lock.writer_id, &mdb->lock.mutex);
 #endif
    }
 }
