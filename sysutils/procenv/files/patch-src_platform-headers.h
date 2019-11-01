--- src/platform-headers.h.orig	2019-08-02 20:40:49 UTC
+++ src/platform-headers.h
@@ -98,7 +98,7 @@ typedef struct statfs procenv_mnt_type;
 #endif
 
 #if defined (HAVE_SYS_CAPABILITY_H)
-#include <sys/capability.h>
+#include <sys/capsicum.h>
 #endif
 
 #if defined (__GLIBC__)
@@ -263,7 +263,7 @@ typedef struct statfs procenv_mnt_type;
 #include <link.h>
 
 #if defined (HAVE_SYS_CAPABILITY_H)
-#include <sys/capability.h>
+#include <sys/capsicum.h>
 #endif
 
 #define PROCENV_CPU_TYPE     int
