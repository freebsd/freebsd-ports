--- physnode.c.orig	Sat Oct  7 21:33:27 2006
+++ physnode.c	Sat Oct  7 21:33:30 2006
@@ -305,12 +305,12 @@
 }
 
 EXPORT void bytecopy(dst, src, bytes)
-VOID *dst;
-VOID const *src;
+char *dst;
+char const *src;
 int bytes;
 {
 	while (bytes--)
-		*((char *)dst)++ = *((char const *)src)++;
+		*dst++ = *src++;
 }
 
 EXPORT NODEP copynode(n)	/* Create a duplicate of node n (including sub-nodes) */
