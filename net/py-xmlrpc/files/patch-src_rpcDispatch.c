
$FreeBSD$

--- src/rpcDispatch.c
+++ src/rpcDispatch.c
@@ -68,7 +68,7 @@
 		rpcDispClear(dp);
 		free(dp->srcs);
 	}
-	PyMem_DEL(dp);
+	PyObject_DEL(dp);
 }
 
 
