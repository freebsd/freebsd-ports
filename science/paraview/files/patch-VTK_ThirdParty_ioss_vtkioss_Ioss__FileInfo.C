--- VTK/ThirdParty/ioss/vtkioss/Ioss_FileInfo.C.orig	2022-11-14 01:44:43 UTC
+++ VTK/ThirdParty/ioss/vtkioss/Ioss_FileInfo.C
@@ -27,7 +27,7 @@
 #endif
 #else
 #include <sys/unistd.h>
-#if defined(__APPLE__) && defined(__MACH__)
+#if (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__)
 #include <sys/param.h>
 #include <sys/mount.h>
 #else
