--- source3/modules/vfs_virusfilter_utils.c.orig	2019-01-15 10:07:00 UTC
+++ source3/modules/vfs_virusfilter_utils.c
@@ -392,6 +392,10 @@ bool virusfilter_io_writel(
 
 bool virusfilter_io_writefl(
 	struct virusfilter_io_handle *io_h,
+	const char *data_fmt, ...) PRINTF_ATTRIBUTE(2, 3);
+
+bool virusfilter_io_writefl(
+	struct virusfilter_io_handle *io_h,
 	const char *data_fmt, ...)
 {
 	va_list ap;
@@ -415,6 +419,10 @@ bool virusfilter_io_writefl(
 
 bool virusfilter_io_vwritefl(
 	struct virusfilter_io_handle *io_h,
+	const char *data_fmt, va_list ap) PRINTF_ATTRIBUTE(2, 0);
+
+bool virusfilter_io_vwritefl(
+	struct virusfilter_io_handle *io_h,
 	const char *data_fmt, va_list ap)
 {
 	char data[VIRUSFILTER_IO_BUFFER_SIZE + VIRUSFILTER_IO_EOL_SIZE];
@@ -666,6 +674,11 @@ bool virusfilter_io_readl(TALLOC_CTX *ct
 bool virusfilter_io_writefl_readl(
 	struct virusfilter_io_handle *io_h,
 	char **read_line,
+	const char *fmt, ...) PRINTF_ATTRIBUTE(3, 4);
+
+bool virusfilter_io_writefl_readl(
+	struct virusfilter_io_handle *io_h,
+	char **read_line,
 	const char *fmt, ...)
 {
 	bool ok;
