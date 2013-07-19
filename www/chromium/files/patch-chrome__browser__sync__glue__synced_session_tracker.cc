--- chrome/browser/sync/glue/synced_session_tracker.cc	2013-07-03 23:46:07.000000000 -0400
+++ chrome/browser/sync/glue/synced_session_tracker.cc	2013-07-19 01:50:13.000000000 -0400
@@ -232,7 +232,7 @@
   }
   DCHECK(window_ptr);
   DCHECK_EQ(window_ptr->window_id.id(), window_id);
-  DCHECK_EQ(reinterpret_cast<SessionWindow*>(NULL),
+  DCHECK_EQ(static_cast<SessionWindow*>(0),
             GetSession(session_tag)->windows[window_id]);
   GetSession(session_tag)->windows[window_id] = window_ptr;
 }
