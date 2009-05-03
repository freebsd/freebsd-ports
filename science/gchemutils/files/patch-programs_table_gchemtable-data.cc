--- programs/table/gchemtable-data.cc.orig	2009-05-03 13:56:09.000000000 -0400
+++ programs/table/gchemtable-data.cc	2009-05-03 13:57:00.000000000 -0400
@@ -114,11 +114,11 @@ gct_data_scalar_init (GObject *obj)
 
 GSF_CLASS (GctDataScalar, gct_data_scalar,
 	   gct_data_scalar_class_init, gct_data_scalar_init,
-	   GO_DATA_SCALAR_TYPE)
+	   GO_TYPE_DATA_SCALAR)
 
 void gct_data_scalar_new (char const *name, void (*loader) (double *value))
 {
-	GctDataScalar *sc = GCT_DATA_SCALAR (g_object_new (GO_DATA_SCALAR_TYPE, NULL));
+	GctDataScalar *sc = GCT_DATA_SCALAR (g_object_new (GO_TYPE_DATA_SCALAR, NULL));
 	sc->loader = loader;
 	GctScalars[name] = GO_DATA (sc);
 
@@ -242,7 +242,7 @@ gct_data_vector_init (GObject *obj)
 
 GSF_CLASS (GctDataVector, gct_data_vector,
 	   gct_data_vector_class_init, gct_data_vector_init,
-	   GO_DATA_VECTOR_TYPE)
+	   GO_TYPE_DATA_VECTOR)
 
 void gct_data_vector_new (char const *name, void (*loader) (double **values, int *length))
 {
@@ -346,7 +346,7 @@ gct_data_matrix_init (GObject *obj)
 
 GSF_CLASS (GctDataMatrix, gct_data_matrix,
 	   gct_data_matrix_class_init, gct_data_matrix_init,
-	   GO_DATA_MATRIX_TYPE)
+	   GO_TYPE_DATA_MATRIX)
 
 void gct_data_matrix_new (char const *name, void (*loader) (double **values, int *cols, int *rows))
 {
