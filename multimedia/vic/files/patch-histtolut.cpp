--- render/histtolut/histtolut.cpp.orig	Thu Jan 23 18:13:08 2003
+++ render/histtolut/histtolut.cpp	Thu Jan 23 18:15:11 2003
@@ -62,6 +62,7 @@
 #endif
 #include <sys/stat.h>
 #include <fcntl.h>
+#include <cstring>
 
 #ifdef WIN32
 extern "C" {
@@ -142,7 +143,7 @@
  * For further details see "Introduction to Algorithms" by Carmen,
  * Lieserson and Rivest.
  */
-//extern void *memset(void *, int, size_t);
+//extern void *std::memset(void *, int, size_t);
 
 /* XXX should pass backup array in as argument, that way can create it
    only once. */
@@ -154,7 +155,7 @@
  \
 	register histItem** hist = &h[idx]; \
 	int j; \
-	memset((void *)aux, 0, 256 * sizeof(int)); \
+	std::memset((void *)aux, 0, 256 * sizeof(int)); \
 	for (j = 0; j < n; j++) \
 		aux[hist[j]->c.fld]++; \
 	 \
@@ -199,7 +200,7 @@
 	box* bv = new box[sizeof(box) * newcolors];
 
 	register u_char* colormap = cmap;
-	memset(colormap, 0, 3 * newcolors);
+	std::memset(colormap, 0, 3 * newcolors);
 
 	/* Set up the initial box. */
 	bv[0].ind = 0;
@@ -450,7 +451,7 @@
 	box* bv = new box[sizeof(box) * newcolors];
 
 	register u_char* colormap = cmap;
-	memset(colormap, 0, 3 * newcolors);
+	std::memset(colormap, 0, 3 * newcolors);
 
 	/* Set up the initial box. */
 	bv[0].ind = 0;
@@ -639,7 +640,7 @@
 		abort();
 
 	int ncol[MAX_YLEVELS];
-	memset(ncol, 0, sizeof(ncol));
+	std::memset(ncol, 0, sizeof(ncol));
 	/* 
 	 * We do this in two passes so that the size of the table can be 
 	 * calculated.  Otherwise it would be have to be too big:
@@ -657,7 +658,7 @@
 		table[i] = new histItem[ncol[i]];
 
 	i = 0;
-	memset(ncol, 0, sizeof(ncol));
+	std::memset(ncol, 0, sizeof(ncol));
 	for (v = 0; v < 1 << 5; ++v) {
 		for (int u = 0; u < 1 << 5; ++u) {
 			for (int y = 0; y < 1 << 4; ++y) {
@@ -688,7 +689,7 @@
 	}
 
 	histItem** histogram[MAX_YLEVELS];
-	memset(histogram, 0, sizeof(histogram));
+	std::memset(histogram, 0, sizeof(histogram));
 	int totcol = 0;
 	for (i = 0; i < ny; ++i) {
 		if (ncol[i] != 0) {
