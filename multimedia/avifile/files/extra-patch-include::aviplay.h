--- include/aviplay.h.orig	Fri Aug  6 12:35:41 2004
+++ include/aviplay.h	Fri Aug  6 12:36:36 2004
@@ -12,8 +12,8 @@
 #include "image.h"
 #include "avm_args.h"
 
-typedef void (*KILLHANDLER)(int, void* p = 0);
-typedef int (*AUDIOFUNC)(void* srcdata, unsigned int size, void* p = 0);
+typedef void (*KILLHANDLER)(int, void* p);
+typedef int (*AUDIOFUNC)(void* srcdata, unsigned int size, void* p);
 
 AVM_BEGIN_NAMESPACE;
 
