--- src/mkvtoolnix-gui/jobs/program_runner/linux_program_runner.cpp.orig	2022-03-13 12:54:56 UTC
+++ src/mkvtoolnix-gui/jobs/program_runner/linux_program_runner.cpp
@@ -1,11 +1,13 @@
 #include "common/common_pch.h"
 
-#if defined(SYS_LINUX)
+#if !defined(SYS_APPLE) && !defined(SYS_WINDOWS)
 
 #include <QDebug>
 #include <QProcess>
 
+#include "common/fs_sys_helpers.h"
 #include "common/list_utils.h"
+#include "common/path.h"
 #include "common/qt.h"
 #include "mkvtoolnix-gui/jobs/program_runner/linux_program_runner.h"
 
@@ -24,6 +26,9 @@ LinuxProgramRunner::isRunProgramTypeSupported(Util::Se
   if (ProgramRunner::isRunProgramTypeSupported(type))
     return true;
 
+  if (mtx::sys::find_exe_in_path(mtx::fs::to_path("systemctl")).empty())
+    return false;
+
   return mtx::included_in(type, Util::Settings::RunProgramType::ShutDownComputer, Util::Settings::RunProgramType::HibernateComputer, Util::Settings::RunProgramType::SleepComputer);
 }
 
@@ -57,4 +62,4 @@ LinuxProgramRunner::sleepComputer(Util::Settings::RunP
 
 }
 
-#endif  // SYS_LINUX
+#endif  // !SYS_APPLE && !SYS_WINDOWS
