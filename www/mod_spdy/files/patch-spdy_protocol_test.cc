--- net/spdy/spdy_protocol_test.cc.org	2012-03-31 16:28:55.670784000 +0900
+++ net/spdy/spdy_protocol_test.cc	2012-03-31 20:49:17.303795861 +0900
@@ -239,13 +239,13 @@
   frame.set_stream_id(0);
   // TODO(mbelshe):  implement EXPECT_DEBUG_DEATH on windows.
 #ifndef WIN32
-  EXPECT_DEBUG_DEATH(frame.set_stream_id(~0), "");
+  EXPECT_DEATH_IF_SUPPORTED(frame.set_stream_id(~0), "");
 #endif
   EXPECT_FALSE(frame.is_control_frame());
 
   frame.set_flags(0);
 #ifndef WIN32
-  EXPECT_DEBUG_DEATH(frame.set_length(~0), "");
+  EXPECT_DEATH_IF_SUPPORTED(frame.set_length(~0), "");
 #endif
   EXPECT_EQ(0, frame.flags());
 }
