-- Define and implement the 'indentlevel' glog flag and associated
-- InsertIndentationIntoEachLine helper added by PaddlePaddle.
--- third_party/glog/src/logging.cc.orig	2019-03-22 02:51:46 UTC
+++ third_party/glog/src/logging.cc
@@ -109,6 +109,8 @@ GLOG_DEFINE_bool(colorlogtostderr, false,
                  "log messages go to stderr in addition to logfiles");
 GLOG_DEFINE_bool(colorlogtostderr, false,
                  "color messages logged to stderr (if supported by terminal)");
+GLOG_DEFINE_int32(indentlevel, 0,
+                 "the indent level of everylines in log messages");
 #ifdef OS_LINUX
 GLOG_DEFINE_bool(drop_log_memory, true, "Drop in-memory buffers of log contents. "
                  "Logs can grow very quickly and they are rarely read before they "
@@ -672,6 +674,25 @@ inline void LogDestination::SetEmailLogging(LogSeverit
   LogDestination::email_logging_severity_ = min_severity;
   LogDestination::addresses_ = addresses;
 }
+std::string InsertIndentationIntoEachLine(const char* message,const int indent_num, const int len) {
+  std::ostringstream sout;
+  std::string str(message);
+  str = str.substr(0,len);
+  int start_pos = 0;
+  int end_pos = 0;
+  std::string indents = "";
+  for (int i = 0; i < indent_num; ++i) {
+    indents += "\t";
+  }
+  while ((end_pos = str.find_first_of('\n', start_pos)) != std::string::npos) {
+    sout << indents  << str.substr(start_pos, end_pos - start_pos + 1);
+    start_pos = end_pos + 1;
+  }
+  if(len - start_pos > 0){
+    sout << indents << str.substr(start_pos, len - start_pos + 1) ;
+  }
+  return sout.str();
+}
 
 static void ColoredWriteToStderr(LogSeverity severity,
                                  const char* message, size_t len) {
@@ -681,6 +702,12 @@ static void ColoredWriteToStderr(LogSeverity severity,
 
   // Avoid using cerr from this module since we may get called during
   // exit code, and cerr may be partially or fully destroyed by then.
+  std::string indent_log_str;
+  if(FLAGS_indentlevel > 0){
+    indent_log_str = InsertIndentationIntoEachLine(message, FLAGS_indentlevel,len);
+    message = indent_log_str.c_str();
+    len = indent_log_str.size();
+  }
   if (COLOR_DEFAULT == color) {
     fwrite(message, len, 1, stderr);
     return;
@@ -707,6 +734,7 @@ static void ColoredWriteToStderr(LogSeverity severity,
   fprintf(stderr, "\033[0;3%sm", GetAnsiColorCode(color));
   fwrite(message, len, 1, stderr);
   fprintf(stderr, "\033[m");  // Resets the terminal to default.
+  fflush(stderr);
 #endif  // OS_WINDOWS
 }
 
