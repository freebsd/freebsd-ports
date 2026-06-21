-- Declare the 'indentlevel' glog flag in the Windows glog header, mirroring
-- the change in src/glog/logging.h.in for Windows builds.
--- third_party/glog/src/windows/glog/logging.h.orig	2019-03-22 02:51:46 UTC
+++ third_party/glog/src/windows/glog/logging.h
@@ -347,6 +347,9 @@ DECLARE_int32(stderrthreshold);
 // stderr in addition to log files.
 DECLARE_int32(stderrthreshold);
 
+//The indent level for every lines in log message
+DECLARE_int32(indentlevel);
+
 // Set whether the log prefix should be prepended to each line of output.
 DECLARE_bool(log_prefix);
 
