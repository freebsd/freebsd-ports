--- src/cats/sql.c.orig	2009-04-12 11:07:46.218959381 -0400
+++ src/cats/sql.c	2009-04-12 11:08:15.509974021 -0400
@@ -759,7 +759,7 @@
    if (mdb->lock.valid == RWLOCK_VALID) { 
       fprintf(fp, "\tRWLOCK=%p w_active=%i w_wait=%i\n", &mdb->lock, mdb->lock.w_active, mdb->lock.w_wait);
 #ifndef HAVE_WIN32
-      fprintf(fp, "\t\tthreadid=0x%x mutex=%p\n", (int)mdb->lock.writer_id, &mdb->lock.mutex);
+      fprintf(fp, "\t\tthreadid=0x%lx mutex=%p\n", (long)mdb->lock.writer_id, &mdb->lock.mutex);
 #endif
    }
 }
