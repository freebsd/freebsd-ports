src/pycryptopp/publickey/ecdsamodule.cpp:94:16: error: cannot initialize return object of type 'int' with an rvalue of type 'nullptr_t'
        return NULL;
               ^~~~

--- src/pycryptopp/publickey/ecdsamodule.cpp.orig	2018-08-28 13:11:32 UTC
+++ src/pycryptopp/publickey/ecdsamodule.cpp
@@ -91,7 +91,7 @@ VerifyingKey___init__(PyObject* self, PyObject* args, 
     Py_ssize_t serializedverifyingkeysize = 0;
 
     if (!PyArg_ParseTupleAndKeywords(args, kwdict, "t#:VerifyingKey__init__", const_cast<char**>(kwlist), &serializedverifyingkey, &serializedverifyingkeysize))
-        return NULL;
+        return 0;
     assert (serializedverifyingkeysize >= 0);
 
     if (serializedverifyingkeysize != 33) {
