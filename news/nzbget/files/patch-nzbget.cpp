--- nzbget.cpp	2008-09-11 13:42:36.000000000 -0700
+++ nzbget.cpp	2008-10-02 16:57:26.000000000 -0700
@@ -41,7 +41,9 @@
 #include <pwd.h>
 #include <grp.h>
 #include <sys/resource.h>
+#ifndef __FreeBSD__
 #include <sys/prctl.h>
+#endif
 #include <signal.h>
 #endif
 #include <sys/types.h>
@@ -82,7 +84,9 @@
 void InstallSignalHandlers();
 void Daemonize();
 void PrintBacktrace();
+#ifndef __FreeBSD__
 void EnableDumpCore();
+#endif
 #ifdef DEBUG
 void MakeSegFault();
 #endif
@@ -170,11 +174,13 @@
 	}
 
 #ifndef WIN32
+#ifndef __FreeBSD__
 	if (g_pOptions->GetDumpCore())
 	{
 		EnableDumpCore();
 	}
 #endif
+#endif
 
 	Run();
 
@@ -518,6 +524,7 @@
 }
 #endif
 
+#ifndef __FreeBSD__
 /**
 * activates the creation of core-files
 */
@@ -530,6 +537,8 @@
 	prctl(PR_SET_DUMPABLE, 1);
 }
 #endif
+#endif
+
 
 void Cleanup()
 {
