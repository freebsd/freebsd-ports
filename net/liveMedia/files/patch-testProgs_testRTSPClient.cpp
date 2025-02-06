Fix build.

testRTSPClient.cpp:64:24: error: copying variable of type 'EventLoopWatchVariable' (aka 'atomic<char>') invokes deleted constructor
   64 | EventLoopWatchVariable eventLoopWatchVariable = 0;

--- testProgs/testRTSPClient.cpp.orig	2025-01-17 15:16:46 UTC
+++ testProgs/testRTSPClient.cpp
@@ -61,7 +61,7 @@ void usage(UsageEnvironment& env, char const* progName
   env << "\t(where each <rtsp-url-i> is a \"rtsp://\" URL)\n";
 }
 
-EventLoopWatchVariable eventLoopWatchVariable = 0;
+EventLoopWatchVariable eventLoopWatchVariable;
 
 int main(int argc, char** argv) {
   // Begin by setting up our usage environment:
