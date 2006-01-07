--- qdvdauthor/log.cpp.orig	Fri Dec 30 03:27:58 2005
+++ qdvdauthor/log.cpp	Fri Dec 30 03:28:15 2005
@@ -83,7 +83,7 @@
   log (iLogLevel, (const char *)qsLog);
 }
 
-void Log::line (void *pObj, unsigned long iThreadID, const char *pFile, const char *pFunction, long iLine, type enLogLevel)
+void Log::line (void *pObj, pthread_t iThreadID, const char *pFile, const char *pFunction, long iLine, type enLogLevel)
 {
   m_cBuffer[0] = '\0';
   if (enLogLevel < m_enLogLevel) {
