--- physnode.c.orig	1998-08-29 14:17:12 UTC
+++ physnode.c
@@ -305,12 +305,12 @@ NODEP n;
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
