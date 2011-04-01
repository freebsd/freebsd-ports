--- ./chrome/test/chrome_process_util.cc.orig	2010-12-16 02:12:11.000000000 +0100
+++ ./chrome/test/chrome_process_util.cc	2010-12-20 20:15:08.000000000 +0100
@@ -61,7 +61,7 @@
     result.push_back(process_entry->pid());
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // On Linux we might be running with a zygote process for the renderers.
   // Because of that we sweep the list of processes again and pick those which
   // are children of one of the processes that we've already seen.
@@ -72,9 +72,9 @@
     while (const base::ProcessEntry* process_entry = it.NextProcessEntry())
       result.push_back(process_entry->pid());
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_POSIX)
   // On Mac OS X we run the subprocesses with a different bundle, and
   // on Linux via /proc/self/exe, so they end up with a different
   // name.  We must collect them in a second pass.
