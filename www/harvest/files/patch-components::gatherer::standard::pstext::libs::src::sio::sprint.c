--- ./components/gatherer/standard/pstext/libs/src/sio/sprint.c.orig	Fri Jan 31 17:25:04 2003
+++ ./components/gatherer/standard/pstext/libs/src/sio/sprint.c	Fri Aug  1 13:24:58 2003
@@ -132,6 +132,15 @@
  *     - all floating point arguments are passed as doubles
  */
 /* VARARGS2 */
+#if defined(__STRICT_ANSI__)
+int Sprint( int fd, char *fmt,... )
+{
+	__sio_descriptor_t *dp = &__sio_descriptors[ fd ] ;
+	register __sio_od_t *odp = ODP( dp ) ;
+	register int cc ;
+	va_list ap ;
+	va_start( ap,fmt ) ;
+#else
 int Sprint( fd, fmt, va_alist )
 	int fd ;
 	register char *fmt ;
@@ -141,10 +150,10 @@
 	register __sio_od_t *odp = ODP( dp ) ;
 	register int cc ;
 	va_list ap ;
-
+	va_start( ap ) ;
+#endif
 	IO_SETUP( fd, dp, __SIO_OUTPUT_STREAM, SIO_ERR ) ;
 
-	va_start( ap ) ;
 	cc = __sio_converter( odp, fd, fmt, ap ) ;
 	va_end( ap ) ;
 	return( cc ) ;
