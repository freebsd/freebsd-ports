--- ui/gfx/x/connection.cc.orig	2026-09-25 15:26:43 UTC
+++ ui/gfx/x/connection.cc
@@ -389,7 +389,7 @@ bool Connection::HasNextEvent() {
     }
     events_.pop_front();
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Move an event from XCB's internal queue to our queue, if available.
   return ReadResponse(/*queued=*/false);
 #else
