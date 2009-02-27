
$FreeBSD$

--- src/rpcBoolean.c
+++ src/rpcBoolean.c
@@ -46,7 +46,7 @@
 static void
 rpcBoolDealloc(rpcBool *bp)
 {
-	PyMem_DEL(bp);
+	PyObject_DEL(bp);
 }
 
 
