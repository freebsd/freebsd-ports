--- src/datastore.c.orig	2025-04-09 19:03:00 UTC
+++ src/datastore.c
@@ -93,17 +93,24 @@ static void convert_external_to_internal(dsh_t *dsh, d
 
 static void convert_external_to_internal(dsh_t *dsh, dbv_const_t *ex_data, dsv_t *in_data)
 {
-    size_t i = 0;
-    const uint32_t *cv = (const uint32_t *)ex_data->data;
+    size_t i = 0u;
+    const uint32_t len = ex_data->leng;
+    uint32_t cv[3] = {0u, 0u, 0u};
+
+    // ensure we don't break on misaligned access
+    if (len < 4u) abort();
+    memcpy(&cv, ex_data->data, min(ex_data->leng, sizeof(cv)));
 
-    in_data->spamcount = !dsh->is_swapped ? cv[i++] : swap_32bit(cv[i++]);
+    in_data->spamcount = !dsh->is_swapped ? cv[i] : swap_32bit(cv[i]);
+    ++i;
 
-    if (ex_data->leng <= i * sizeof(uint32_t))
+    if (len < (i + 1) * sizeof(uint32_t))
 	in_data->goodcount = 0;
     else
-	in_data->goodcount = !dsh->is_swapped ? cv[i++] : swap_32bit(cv[i++]);
+	in_data->goodcount = !dsh->is_swapped ? cv[i] : swap_32bit(cv[i]);
+    ++i;
 
-    if (ex_data->leng <= i * sizeof(uint32_t))
+    if (len < (i + 1) * sizeof(uint32_t))
 	in_data->date = 0;
     else
 	in_data->date = !dsh->is_swapped ? cv[i] : swap_32bit(cv[i]);
@@ -113,8 +120,8 @@ static void convert_internal_to_external(dsh_t *dsh, d
 
 static void convert_internal_to_external(dsh_t *dsh, dsv_t *in_data, dbv_t *ex_data)
 {
-    size_t i = 0;
-    uint32_t *cv = (uint32_t *)ex_data->data;
+    size_t i = 0u;
+    uint32_t cv[3] = {0u, 0u, 0u};
 
     /* Writing requires extra magic since the counts may need to be
     ** separated for output to different wordlists.
@@ -127,6 +133,7 @@ static void convert_internal_to_external(dsh_t *dsh, d
 	cv[i++] = !dsh->is_swapped ? in_data->date : swap_32bit(in_data->date);
 
     ex_data->leng = i * sizeof(cv[0]);
+    memcpy(ex_data->data, &cv, i * sizeof(cv[0]));
 
     return;
 }
