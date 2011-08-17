--- ./source4/auth/pyauth.h.orig	2010-01-11 06:35:28.000000000 +0100
+++ ./source4/auth/pyauth.h	2011-08-05 17:45:16.000000000 +0200
@@ -20,7 +20,7 @@
 #ifndef _PYAUTH_H_
 #define _PYAUTH_H_
 
-#include "pytalloc.h"
+#include "lib/talloc/pytalloc.h"
 #include "auth/session.h"
 
 PyAPI_DATA(PyTypeObject) PyAuthSession;
