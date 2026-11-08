--- source3/modules/vfs_virusfilter_utils.c.orig	2026-01-20 15:42:54 UTC
+++ source3/modules/vfs_virusfilter_utils.c
@@ -401,6 +401,10 @@ bool PRINTF_ATTRIBUTE(2, 3) virusfilter_io_writefl(
 
 bool PRINTF_ATTRIBUTE(2, 3) virusfilter_io_writefl(
 	struct virusfilter_io_handle *io_h,
+	const char *data_fmt, ...) PRINTF_ATTRIBUTE(2, 3);
+
+bool virusfilter_io_writefl(
+	struct virusfilter_io_handle *io_h,
 	const char *data_fmt, ...)
 {
 	va_list ap;
@@ -424,6 +428,10 @@ bool PRINTF_ATTRIBUTE(2, 0) virusfilter_io_vwritefl(
 
 bool PRINTF_ATTRIBUTE(2, 0) virusfilter_io_vwritefl(
 	struct virusfilter_io_handle *io_h,
+	const char *data_fmt, va_list ap) PRINTF_ATTRIBUTE(2, 0);
+
+bool virusfilter_io_vwritefl(
+	struct virusfilter_io_handle *io_h,
 	const char *data_fmt, va_list ap)
 {
 	char data[VIRUSFILTER_IO_BUFFER_SIZE + VIRUSFILTER_IO_EOL_SIZE];
@@ -673,6 +681,11 @@ bool PRINTF_ATTRIBUTE(3, 4) virusfilter_io_writefl_rea
 }
 
 bool PRINTF_ATTRIBUTE(3, 4) virusfilter_io_writefl_readl(
+	struct virusfilter_io_handle *io_h,
+	char **read_line,
+	const char *fmt, ...) PRINTF_ATTRIBUTE(3, 4);
+
+bool virusfilter_io_writefl_readl(
 	struct virusfilter_io_handle *io_h,
 	char **read_line,
 	const char *fmt, ...)
