--- ./chrome/browser/sync/engine/syncer_thread.cc.orig	2010-12-16 02:11:54.000000000 +0100
+++ ./chrome/browser/sync/engine/syncer_thread.cc	2010-12-20 20:15:08.000000000 +0100
@@ -264,7 +264,7 @@
   bool initial_sync_for_thread = true;
   bool continue_sync_cycle = false;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   idle_query_.reset(new IdleQueryLinux());
 #endif
 
@@ -359,7 +359,7 @@
         static_cast<int>(vault_.current_wait_interval_.poll_delta.InSeconds()),
         &user_idle_milliseconds, &continue_sync_cycle, nudged);
   }
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   idle_query_.reset();
 #endif
 }
@@ -833,7 +833,7 @@
     return 0;
   }
   return idle_time / 1000000;  // nano to milli
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   if (idle_query_.get())
     return idle_query_->IdleTime();
   return 0;
