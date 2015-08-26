--- src/ext/easylogging++.h.orig	2014-03-28 09:35:09.000000000 +0100
+++ src/ext/easylogging++.h	2015-08-23 00:44:41.276551000 +0200
@@ -3586,7 +3586,7 @@ class LogMessage {
     LogMessage(const Level& level, const char* file, unsigned long int line, const char* func,  // NOLINT
                           base::VRegistry::VLevel verboseLevel, Logger* logger) :
                   m_level(level), m_file(file), m_line(line), m_func(func),
-                  m_verboseLevel(verboseLevel), m_logger(logger), m_message(std::move(logger->stream().str())) {
+                  m_verboseLevel(verboseLevel), m_logger(logger), m_message(logger->stream().str()) {
     }
     inline const Level& level(void) const { return m_level; }
     inline const char* file(void) const { return m_file; }
@@ -3895,7 +3895,7 @@ class LogDispatcher : base::NoCopy {
         if (ELPP->hasFlag(LoggingFlag::StrictLogFileSizeCheck)) {
             tc->validateFileRolling(m_logMessage.level(), ELPP->preRollOutHandler());
         }
-        dispatch(std::move(m_logMessage.logger()->logBuilder()->build(&m_logMessage, m_dispatchAction == base::DispatchAction::NormalLog)));
+        dispatch(m_logMessage.logger()->logBuilder()->build(&m_logMessage, m_dispatchAction == base::DispatchAction::NormalLog));
         if (lockLogger) {
             m_logMessage.logger()->unlock();
         }
