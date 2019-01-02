--- netifaces.c.orig	2019-01-02 06:57:05 UTC
+++ netifaces.c
@@ -2007,7 +2007,7 @@ gateways (PyObject *self)
     buffer = ptr;
 
     ret = sysctl (mib, 6, buffer, &len, 0, 0);
-  } while (ret != 0 || errno == ENOMEM || errno == EINTR);
+  } while (ret != 0 && (errno == ENOMEM || errno == EINTR));
 
   if (ret < 0) {
     PyErr_SetFromErrno (PyExc_OSError);
