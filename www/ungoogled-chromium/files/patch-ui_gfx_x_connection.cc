--- ui/gfx/x/connection.cc.orig	2026-02-15 10:01:45 UTC
+++ ui/gfx/x/connection.cc
@@ -411,7 +411,7 @@ bool Connection::HasNextEvent() {
     }
     events_.pop_front();
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Move an event from XCB's internal queue to our queue, if available.
   return ReadResponse(/*queued=*/false);
 #else
