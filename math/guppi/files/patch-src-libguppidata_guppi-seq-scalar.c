--- src/libguppidata/guppi-seq-scalar.c.orig	2007-12-13 15:33:12.000000000 +0100
+++ src/libguppidata/guppi-seq-scalar.c	2007-12-13 15:33:37.000000000 +0100
@@ -1775,8 +1775,6 @@
 static void
 guppi_seq_scalar_class_init (GuppiSeqScalarClass *klass)
 {
-  static GtkWidget *info_display (GuppiData *);
-
   GtkObjectClass *object_class = (GtkObjectClass *) klass;
   GuppiDataClass *data_class = GUPPI_DATA_CLASS (klass);
   GuppiSeqClass *seq_class = GUPPI_SEQ_CLASS (klass);
