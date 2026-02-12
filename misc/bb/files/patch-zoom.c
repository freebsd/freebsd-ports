--- zoom.c.orig	2026-02-12 17:47:35 UTC
+++ zoom.c
@@ -241,13 +241,13 @@ static /*INLINE */ void mkrealloc_table(register numbe
 #endif
     if (dyndata == NULL) {
 	fprintf(stderr, "XaoS fatal error:Could not allocate memory for"
-		"temporary dynamical data of size:%i\n"
+		"temporary dynamical data of size:%zu\n"
 		"I am unable to handle this problem so please resize to lower window\n", (size) * (DSIZE + 1) * sizeof(struct dyn_data) + size * sizeof(int) + size * sizeof(int));
 	return;
     }
     if (best == NULL) {
 	fprintf(stderr, "XaoS fatal error:Could not allocate memory for"
-		"temporary dynamical data of size:%i\n"
+		"temporary dynamical data of size:%zu\n"
 		"I am unable to handle this problem so please resize to lower window\n", (size) * (DSIZE + 1) * sizeof(struct dyn_data) + size * sizeof(int) + size * sizeof(int));
 #ifndef HAVE_ALLOCA
 	free(dyndata);
@@ -256,7 +256,7 @@ static /*INLINE */ void mkrealloc_table(register numbe
     }
     if (best1 == NULL) {
 	fprintf(stderr, "XaoS fatal error:Could not allocate memory for"
-		"temporary dynamical data of size:%i\n"
+		"temporary dynamical data of size:%zu\n"
 		"I am unable to handle this problem so please resize to lower window\n", (size) * (DSIZE + 1) * sizeof(struct dyn_data) + size * sizeof(int) + size * sizeof(int));
 #ifndef HAVE_ALLOCA
 	free(dyndata);
@@ -586,13 +586,13 @@ static /*INLINE */ void moveoldpoints(void)
 #endif
     if (size == NULL) {
 	fprintf(stderr, "XaoS fratal error:Could not allocate memory for"
-		"temporary dynamical data of size:%i\n"
+		"temporary dynamical data of size:%zu\n"
 		"I am unable to handle this problem so please resize to lower window\n", 2 * d->width * sizeof(int));
 	return;
     }
     if (start == NULL) {
 	fprintf(stderr, "XaoS fratal error:Could not allocate memory for"
-		"temporary dynamical data of size:%i\n"
+		"temporary dynamical data of size:%zu\n"
 		"I am unable to handle this problem so please resize to lower window\n", 2 * d->width * sizeof(int));
 #ifndef HAVE_ALLOCA
 	free(size);
