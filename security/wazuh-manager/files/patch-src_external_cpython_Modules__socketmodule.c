--- src/external/cpython/Modules/socketmodule.c
+++ src/external/cpython/Modules/socketmodule.c
@@ -1850,6 +1850,11 @@ getsockaddrarg(PySocketSockObject *s, PyObject *args,
         /* RDS sockets use sockaddr_in: fall-through */
 #endif /* AF_RDS */
 
+#ifdef AF_DIVERT
+    case AF_DIVERT:
+        /* FreeBSD divert(4) sockets use sockaddr_in: fall-through */
+#endif /* AF_DIVERT */
+
     case AF_INET:
     {
         struct maybe_idna host = {NULL, NULL};
@@ -7628,6 +7633,14 @@ PyInit__socket(void)
     PyModule_AddIntMacro(m, AF_SYSTEM);
 #endif
 
+/* FreeBSD divert(4) */
+#ifdef PF_DIVERT
+    PyModule_AddIntMacro(m, PF_DIVERT);
+#endif
+#ifdef AF_DIVERT
+    PyModule_AddIntMacro(m, AF_DIVERT);
+#endif
+
 #ifdef AF_PACKET
     PyModule_AddIntMacro(m, AF_PACKET);
 #endif
