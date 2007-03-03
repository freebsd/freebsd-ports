Index: /trunk/src/deluge_core.cpp
===================================================================
--- src/deluge_core.cpp (revision 205)
+++ src/deluge_core.cpp (revision 292)
@@ -861,4 +861,7 @@
 				"pieces",						py_pieces
 					);
+
+		Py_DECREF(py_pieces); // Assuming the previous line does NOT steal the ref, then this is
+		                      // needed!
 
 		PyTuple_SetItem(ret, i, peer_info);
