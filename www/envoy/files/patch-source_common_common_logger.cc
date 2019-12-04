--- source/common/common/logger.cc.orig	2019-11-24 23:36:11.089013000 +0800
+++ source/common/common/logger.cc	2019-11-24 23:36:22.474417000 +0800
@@ -61,7 +61,7 @@ void DelegatingLogSink::log(const spdlog::details::log
     return;
   }
 
-  fmt::memory_buffer formatted;
+  spdlog::memory_buf_t formatted;
   formatter_->format(msg, formatted);
   lock.Release();
   sink_->log(absl::string_view(formatted.data(), formatted.size()));
