--- src/mkvtoolnix-gui/jobs/program_runner/linux_program_runner.h.orig	2022-03-13 12:54:56 UTC
+++ src/mkvtoolnix-gui/jobs/program_runner/linux_program_runner.h
@@ -2,7 +2,7 @@
 
 #include "common/common_pch.h"
 
-#if defined(SYS_LINUX)
+#if !defined(SYS_APPLE) && !defined(SYS_WINDOWS)
 
 #include "mkvtoolnix-gui/jobs/program_runner.h"
 
@@ -28,4 +28,4 @@ class LinuxProgramRunner: public ProgramRunner { (prot
 
 }}
 
-#endif  // SYS_LINUX
+#endif  // !SYS_APPLE && !SYS_WINDOWS
