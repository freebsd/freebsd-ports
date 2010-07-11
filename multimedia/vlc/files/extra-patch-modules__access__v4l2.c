--- modules/access/v4l2.c.orig	2009-12-21 04:43:39.000000000 +1100
+++ modules/access/v4l2.c	2010-02-19 13:29:51.000000000 +1100
@@ -492,6 +492,9 @@
 {
     void *  start;
     size_t  length;
+#if !defined (HAVE_POSIX_MEMALIGN) && !defined (HAVE_MEMALIGN)
+    void *  free;
+#endif
 };

 struct demux_sys_t
@@ -1038,7 +1041,12 @@
         switch( p_sys->io )
         {
         case IO_METHOD_READ:
-            free( p_sys->p_buffers[0].start );
+#if !defined (HAVE_POSIX_MEMALIGN) && !defined (HAVE_MEMALIGN)
+	    if (p_sys->p_buffers[0].free)
+                free( p_sys->p_buffers[0].free );
+	    else
+#endif
+                free( p_sys->p_buffers[0].start );
             break;

         case IO_METHOD_MMAP:
@@ -1054,7 +1062,12 @@
         case IO_METHOD_USERPTR:
             for( i = 0; i < p_sys->i_nbuffers; ++i )
             {
-               free( p_sys->p_buffers[i].start );
+#if !defined (HAVE_POSIX_MEMALIGN) && !defined (HAVE_MEMALIGN)
+	       if (p_sys->p_buffers[0].free)
+                   free( p_sys->p_buffers[i].free );
+	       else
+#endif
+                   free( p_sys->p_buffers[i].start );
             }
             break;

@@ -1600,10 +1613,31 @@

     for( p_sys->i_nbuffers = 0; p_sys->i_nbuffers < 4; ++p_sys->i_nbuffers )
     {
+#if defined (HAVE_POSIX_MEMALIGN)
         p_sys->p_buffers[p_sys->i_nbuffers].length = i_buffer_size;
         if( posix_memalign( &p_sys->p_buffers[p_sys->i_nbuffers].start,
                 /* boundary */ i_page_size, i_buffer_size ) )
             goto open_failed;
+#elif defined (HAVE_MEMALIGN)
+        p_sys->p_buffers[p_sys->i_nbuffers].length = i_buffer_size;
+	p_sys->p_buffers[p_sys->i_nbuffers].start =
+	    memalign ( /* boundary */ i_page_size, i_buffer_size );
+	if (p_sys->p_buffers[p_sys->i_nbuffers].start == NULL)
+	    goto open_failed;
+#else
+	unsigned char *ptr;
+	size_t align = i_page_size - 1;
+
+        p_sys->p_buffers[p_sys->i_nbuffers].length = i_buffer_size;
+	ptr = malloc (i_buffer_size + align);
+	if ( ptr == NULL )
+	    goto open_failed;
+
+	p_sys->p_buffers[p_sys->i_nbuffers].free = ptr;
+	ptr += align;
+	p_sys->p_buffers[p_sys->i_nbuffers].start =
+		(void *)(((uintptr_t)ptr) & ~align);
+#endif
     }
     return VLC_SUCCESS;
