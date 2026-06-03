--- src/lib/fy-doc.c.orig	2026-01-13 20:43:43 UTC
+++ src/lib/fy-doc.c
@@ -9,6 +9,8 @@
 #include "config.h"
 #endif
 
+#include <sys/param.h>
+
 #include <stdio.h>
 #include <string.h>
 #include <assert.h>
@@ -5753,7 +5755,7 @@ static int fy_node_mapping_sort_cmp(
 }
 
 static int fy_node_mapping_sort_cmp(
-#ifdef __APPLE__
+#if defined(__APPLE__) || __FreeBSD_version < 1400000
 void *arg, const void *a, const void *b
 #else
 const void *a, const void *b, void *arg
@@ -5775,7 +5777,7 @@ static int fy_node_mapping_sort_cmp_no_qsort_r(const v
 
 static int fy_node_mapping_sort_cmp_no_qsort_r(const void *a, const void *b)
 {
-#ifdef __APPLE__
+#if defined(__APPLE__) || __FreeBSD_version < 1400000
 	return fy_node_mapping_sort_cmp(
 			fy_node_mapping_sort_ctx_no_qsort_r,
 			a, b);
@@ -5892,7 +5894,7 @@ void fy_node_mapping_perform_sort(struct fy_node *fyn_
 	ctx.fynpp = fynpp;
 	ctx.count = count;
 #if defined(HAVE_QSORT_R) && HAVE_QSORT_R && !defined(__EMSCRIPTEN__)
-#ifdef __APPLE__
+#if defined(__APPLE__) || __FreeBSD_version < 1400000
 	qsort_r(fynpp, count, sizeof(*fynpp), &ctx, fy_node_mapping_sort_cmp);
 #else
 	qsort_r(fynpp, count, sizeof(*fynpp), fy_node_mapping_sort_cmp, &ctx);
