--- libpst.h.orig	Sat Sep 24 23:28:03 2005
+++ libpst.h	Sun Sep 25 14:23:06 2005
@@ -14,8 +14,9 @@
 
 #ifndef FILETIME_DEFINED
 #define FILETIME_DEFINED
+#include <sys/types.h>
 //Win32 Filetime struct - copied from WINE
-typedef struct {
+typedef struct _FILETIME {
   u_int32_t dwLowDateTime;
   u_int32_t dwHighDateTime;
 } FILETIME;
