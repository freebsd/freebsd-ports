--- mmc.c.orig	Tue Oct 22 09:42:01 2002
+++ mmc.c	Fri Nov 14 12:26:39 2003
@@ -74,6 +74,9 @@
     time_t ctime;
     int refcount;
     time_t reftime;
+#ifdef USE_SENDFILE
+    int fd;
+#endif
     void* addr;
     unsigned int hash;
     int hash_idx;
@@ -140,7 +143,11 @@
 	/* Yep.  Just return the existing map */
 	++m->refcount;
 	m->reftime = now;
+#ifdef USE_SENDFILE
+	return (&m->fd);
+#else
 	return m->addr;
+#endif
 	}
 
     /* Open the file. */
@@ -186,7 +193,9 @@
     else
 	{
 	size_t size_size = (size_t) m->size;	/* loses on files >2GB */
-#ifdef HAVE_MMAP
+#ifdef USE_SENDFILE
+	m->fd = fd;
+#elif defined(HAVE_MMAP)
 	/* Map the file into memory. */
 	m->addr = mmap( 0, size_size, PROT_READ, MAP_PRIVATE, fd, 0 );
 	if ( m->addr == (void*) -1 && errno == ENOMEM )
@@ -234,8 +243,9 @@
 	    }
 #endif /* HAVE_MMAP */
 	}
+#ifndef USE_SENDFILE
     (void) close( fd );
-
+#endif /* !USE_SENDFILE */
     /* Put the Map into the hash table. */
     if ( add_hash( m ) < 0 )
 	{
@@ -253,8 +263,12 @@
     /* Update the total byte count. */
     mapped_bytes += m->size;
 
+#ifdef USE_SENDFILE
+    return (&m->fd);
+#else
     /* And return the address. */
     return m->addr;
+#endif
     }
 
 
@@ -267,14 +281,18 @@
     if ( sbP != (struct stat*) 0 )
 	{
 	m = find_hash( sbP->st_ino, sbP->st_dev, sbP->st_size, sbP->st_ctime );
+#ifndef USE_SENDFILE
 	if ( m != (Map*) 0 && m->addr != addr )
 	    m = (Map*) 0;
+#endif
 	}
+#ifndef USE_SENDFILE
     /* If that didn't work, try a full search. */
     if ( m == (Map*) 0 )
 	for ( m = maps; m != (Map*) 0; m = m->next )
 	    if ( m->addr == addr )
 		break;
+#endif
     if ( m == (Map*) 0 )
 	syslog( LOG_ERR, "mmc_unmap failed to find entry!" );
     else if ( m->refcount <= 0 )
@@ -363,7 +381,9 @@
     m = *mm;
     if ( m->size != 0 )
 	{
-#ifdef HAVE_MMAP
+#ifdef USE_SENDFILE
+	close(m->fd);	    
+#elif defined(HAVE_MMAP)
 	if ( munmap( m->addr, m->size ) < 0 )
 	    syslog( LOG_ERR, "munmap - %m" );
 #else /* HAVE_MMAP */
