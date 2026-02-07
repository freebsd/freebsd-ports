--- src/mem_ops.c.orig	2023-02-20 12:57:16 UTC
+++ src/mem_ops.c
@@ -17,7 +17,7 @@ static void *
 xmalloc_fatal(size_t size) 
 {
 
-	DEBUG("\n Memory FAILURE...\n size dbg: %lu\n",size);
+	DEBUG("\n Memory FAILURE...\n size dbg: %zu\n",size);
 
 	exit(0);
 }
