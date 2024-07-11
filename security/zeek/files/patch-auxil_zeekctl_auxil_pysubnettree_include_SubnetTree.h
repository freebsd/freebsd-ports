--- auxil/zeekctl/auxil/pysubnettree/include/SubnetTree.h.orig	2024-05-16 17:25:57 UTC
+++ auxil/zeekctl/auxil/pysubnettree/include/SubnetTree.h
@@ -147,7 +147,7 @@ class SubnetTree (public)
 
            PyObject* data = self->lookup(cidr, size);
            if ( ! data ) {
-               PyErr_SetString(PyExc_KeyError, cidr);
+               PyErr_SetObject(PyExc_KeyError, PyBytes_FromStringAndSize(cidr, size));
                return 0;
            }
 
