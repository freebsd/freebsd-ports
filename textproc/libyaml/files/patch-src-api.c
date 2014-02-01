# HG changeset patch
# User Florian Weimer <fweimer@redhat.com>
# Date 1389274355 -3600
#      Thu Jan 09 14:32:35 2014 +0100
# Node ID 034d7a91581ac930e5958683f1a06f41e96d24a2
# Parent  a54d7af707f25dc298a7be60fd152001d2b3035b
yaml_stack_extend: guard against integer overflow

diff --git a/src/api.c b/src/api.c
--- src/api.c
+++ src/api.c
@@ -117,7 +117,12 @@
 YAML_DECLARE(int)
 yaml_stack_extend(void **start, void **top, void **end)
 {
-    void *new_start = yaml_realloc(*start, ((char *)*end - (char *)*start)*2);
+    void *new_start;
+
+    if ((char *)*end - (char *)*start >= INT_MAX / 2)
+	return 0;
+
+    new_start = yaml_realloc(*start, ((char *)*end - (char *)*start)*2);
 
     if (!new_start) return 0;
 

