--- qt/pinentrycontroller.cpp.orig	Thu Jan 30 09:25:51 2003
+++ qt/pinentrycontroller.cpp	Thu Jan 30 09:26:15 2003
@@ -56,6 +56,8 @@
   
   assuan_set_malloc_hooks( secmem_malloc, secmem_realloc, secmem_free );
   int rc = assuan_init_pipe_server( &_ctx, fds );
+  assuan_set_log_stream (_ctx, stderr);
+
   if( rc ) {
     qDebug(assuan_strerror( static_cast<AssuanError>(rc) ));
     exit(-1);
