--- ./python/dnet.c.orig	Tue Jul 10 12:35:10 2007
+++ ./python/dnet.c	Tue Jul 10 12:35:59 2007
@@ -2726,7 +2726,7 @@
   PyObject *__pyx_3 = 0;
   unsigned short __pyx_4;
   Py_INCREF(__pyx_v_self);
-  ((PyObject*)__pyx_v_next) = Py_None; Py_INCREF(((PyObject*)__pyx_v_next));
+  __pyx_v_next = Py_None; Py_INCREF(((PyObject*)__pyx_v_next));
 
   /* "/Users/dugsong/projects/libdnet/python/./dnet.pyx":634 */
   __pyx_1 = (((struct __pyx_obj_4dnet___addr_ip4_iter *)__pyx_v_self)->cur <= ((struct __pyx_obj_4dnet___addr_ip4_iter *)__pyx_v_self)->max);
@@ -2738,7 +2738,7 @@
     Py_DECREF(__pyx_2); __pyx_2 = 0;
     if (!__Pyx_TypeTest(__pyx_3, __pyx_ptype_4dnet_addr)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 635; goto __pyx_L1;}
     Py_DECREF(((PyObject *)__pyx_v_next));
-    ((PyObject *)__pyx_v_next) = __pyx_3;
+    __pyx_v_next = __pyx_3;
     __pyx_3 = 0;
 
     /* "/Users/dugsong/projects/libdnet/python/./dnet.pyx":636 */
