--- psi4/src/psi4/libpsio/psio.h.orig	2026-04-20 18:20:27 UTC
+++ psi4/src/psi4/libpsio/psio.h
@@ -47,6 +47,7 @@
 #define PERMISSION_MODE _S_IWRITE
 #else
 #include <unistd.h>
+#include <sys/stat.h>
 #define SYSTEM_WRITE ::write
 #define SYSTEM_READ ::read
 #define SYSTEM_LSEEK ::lseek
