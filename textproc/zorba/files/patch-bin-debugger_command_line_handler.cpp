--- bin/debugger/command_line_handler.cpp.orig	2014-06-26 18:42:05.000000000 +0200
+++ bin/debugger/command_line_handler.cpp	2014-06-26 18:40:21.000000000 +0200
@@ -138,7 +138,7 @@
 
 template<>
 void
-CommandLineHandler::handle<BreakpointSet>(std::tr1::tuple<bstring, bstring, bint> &aTuple)
+CommandLineHandler::handle<BreakpointSet>(ZORBA_TR1_NS::tuple<bstring, bstring, bint> &aTuple)
 {
   DebuggerClient::BreakpointType lType = DebuggerClient::Line;
   bool lEnabled = true;
