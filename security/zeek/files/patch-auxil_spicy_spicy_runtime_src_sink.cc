--- auxil/spicy/spicy/runtime/src/sink.cc.orig	2026-06-10 16:58:45 UTC
+++ auxil/spicy/spicy/runtime/src/sink.cc
@@ -431,7 +431,7 @@ void Sink::_close(bool orderly) {
                         fmt("error in connected unit %s during close (%s)", s->parser->name, err.what()));
                 }
 
-                assert(s->resumable); // must have conluded after freezing/aborting
+                assert(static_cast<bool>(s->resumable)); // must have conluded after freezing/aborting
             }
         }
 
