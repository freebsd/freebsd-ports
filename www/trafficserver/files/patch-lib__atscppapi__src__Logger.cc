--- ./lib/atscppapi/src/Logger.cc.orig	2013-12-05 22:07:48.000000000 +0000
+++ ./lib/atscppapi/src/Logger.cc	2014-01-27 08:45:49.000000000 +0000
@@ -189,7 +189,7 @@
        LOG_DEBUG("logging a " level " to '%s' with length %d", state_->filename_.c_str(), n); \
        TSTextLogObjectWrite(state_->text_log_obj_, const_cast<char*>("[" level "] %s"), buffer); \
      } else { \
-       LOG_ERROR("Unable to log " level " message to '%s' due to size exceeding %lud bytes.", state_->filename_.c_str(), sizeof(buffer)); \
+       LOG_ERROR("Unable to log " level " message to '%s' due to size exceeding %zu bytes.", state_->filename_.c_str(), sizeof(buffer)); \
      } \
      return; \
     }
