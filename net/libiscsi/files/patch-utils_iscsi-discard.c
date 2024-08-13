--- utils/iscsi-discard.c.orig	2024-02-05 23:51:38 UTC
+++ utils/iscsi-discard.c
@@ -220,7 +220,11 @@ int main(int argc, char *argv[])
 
 	capacity = block_length * (rc16->returned_lba + 1);
 	if (offset > capacity) {
+#ifdef __i386__
+		fprintf(stderr,"Offset(%llu) exceeds capacity(%llu)\n", offset, capacity);
+#else
 		fprintf(stderr,"Offset(%lu) exceeds capacity(%lu)\n", offset, capacity);
+#endif
 		goto free_task;
 	}
 
