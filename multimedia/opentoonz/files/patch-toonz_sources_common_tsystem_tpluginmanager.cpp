The sys/dir.h include was dropped in FreeBSD in 
commit  d2ad004b4a797125b14cb36a4e2911089aa079fd
which bumped the verison number to 1300040

--- toonz/sources/common/tsystem/tpluginmanager.cpp.orig	2021-04-11 15:01:57 UTC
+++ toonz/sources/common/tsystem/tpluginmanager.cpp
@@ -15,12 +15,14 @@
 #include <sys/param.h>
 #include <unistd.h>
 #include <sys/types.h>
-#ifndef FREEBSD
+#if !defined(FREEBSD) || __FreeBSD_version >= 1300040
 #include <dirent.h>
 #endif
 #include <stdio.h>
 #include <unistd.h>
+#if !defined(FREEBSD) || __FreeBSD_version < 1300040
 #include <sys/dir.h>
+#endif
 #include <sys/param.h>  // for getfsstat
 #ifdef MACOSX
 #include <sys/ucred.h>
