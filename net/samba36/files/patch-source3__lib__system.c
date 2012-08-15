--- ./source3/lib/system.c.orig	2011-08-09 13:17:47.000000000 +0200
+++ ./source3/lib/system.c	2011-10-13 23:38:02.000000000 +0200
@@ -2586,14 +2586,14 @@
 }
 
 /*******************************************************************
- An aio_fsync wrapper that will deal with 64-bit sizes.
+ An aio_suspend wrapper that will deal with 64-bit sizes.
 ********************************************************************/
 
 int sys_aio_suspend(const SMB_STRUCT_AIOCB * const cblist[], int n, const struct timespec *timeout)
 {
 #if defined(HAVE_EXPLICIT_LARGEFILE_SUPPORT) && defined(HAVE_AIOCB64) && defined(HAVE_AIO_SUSPEND64)
         return aio_suspend64(cblist, n, timeout);
-#elif defined(HAVE_AIO_FSYNC)
+#elif defined(HAVE_AIO_SUSPEND)
         return aio_suspend(cblist, n, timeout);
 #else
 	errno = ENOSYS;
