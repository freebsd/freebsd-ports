--- src/common/compat/dlfcn.h.orig	2022-03-25 15:37:17 UTC
+++ src/common/compat/dlfcn.h
@@ -9,6 +9,8 @@
 #ifndef _UST_COMMON_COMPAT_DLFCN_H
 #define _UST_COMMON_COMPAT_DLFCN_H
 
+typedef long Lmid_t;
+
 #ifdef _DLFCN_H
 #error "Please include compat/dlfcn.h before dlfcn.h."
 #endif /* _DLFCN_H */
