https://github.com/zopefoundation/zope.proxy/commit/f296acc8d1f2a37e0fc1ae76d1f06b730391fda7

--- src/zope/proxy/_zope_proxy_proxy.c.orig	2024-08-06 15:48:48 UTC
+++ src/zope/proxy/_zope_proxy_proxy.c
@@ -311,7 +311,7 @@ wrap_repr(PyObject *wrapper)
     return PyObject_Repr(Proxy_GET_OBJECT(wrapper));
 }
 
-static long
+static Py_hash_t
 wrap_hash(PyObject *self)
 {
     return PyObject_Hash(Proxy_GET_OBJECT(self));
