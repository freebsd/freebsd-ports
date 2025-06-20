Allow using mac_priority(4) to avoid stutter during high load:
- Emulate SCHED_RESET_ON_FORK via pthread_atfork
- Switch to pthread_setschedparam as Linux sched_setscheduler
  operates on threads contrary to POSIX

Similar to picom, sway, hyprland. Also plasma6-kwin but not fixed yet.

--- como/base/wayland/app_singleton.h.orig	2024-02-27 13:02:31 UTC
+++ como/base/wayland/app_singleton.h
@@ -19,12 +19,16 @@ class app_singleton : public base::app_singleton (publ
         setenv("QT_QPA_PLATFORM", "wayland-org.kde.kwin.qpa", true);
         setenv("KWIN_FORCE_OWN_QPA", "1", true);
 
-#if HAVE_SCHED_RESET_ON_FORK
         int const minPriority = sched_get_priority_min(SCHED_RR);
         sched_param sp;
         sp.sched_priority = minPriority;
-        sched_setscheduler(0, SCHED_RR | SCHED_RESET_ON_FORK, &sp);
-#endif
+        if (!pthread_setschedparam(pthread_self(), SCHED_RR, &sp)) {
+            pthread_atfork(NULL, NULL, []() {
+                sched_param sp;
+                sp.sched_priority = 0;
+                pthread_setschedparam(pthread_self(), SCHED_OTHER, &sp);
+            });
+        }
 
         qapp = std::make_unique<QApplication>(argc, argv);
         prepare_qapp();
