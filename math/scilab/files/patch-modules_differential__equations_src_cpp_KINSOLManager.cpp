--- modules/differential_equations/src/cpp/KINSOLManager.cpp.orig	2026-05-19 09:32:07 UTC
+++ modules/differential_equations/src/cpp/KINSOLManager.cpp
@@ -648,16 +648,18 @@ void KINSOLManager::solve()
     m_wstrState = L"init";
     SUNLogger logger;
     SUNErrCode sunerr;
-        
+
     sunerr = SUNContext_GetLogger(m_sunctx,&logger);
     if (sunerr || logger == NULL)
     {
         sprintf(msg,"In KINSOLManager::solve(), SUNContext_GetLogger error, logger=%p, flag=%d\n",(void *)logger, sunerr);
-        throw ast::InternalError(msg);        
+        throw ast::InternalError(msg);
     }
-    
-    intermediateCallback(logger, SUN_LOGLEVEL_INFO, NULL, NULL, "KINSol",NULL);
-    
+
+    // On arm64: error: no viable conversion from 'int' to 'va_list' (aka '__builtin_va_list')
+    va_list noargs{};
+    intermediateCallback(logger, SUN_LOGLEVEL_INFO, NULL, NULL, "KINSol", noargs);
+
     m_wstrState = L"iter";
 
     auto chrono_begin = std::chrono::steady_clock::now();
@@ -670,7 +672,7 @@ void KINSOLManager::solve()
 
     m_wstrState = L"done";
 
-    intermediateCallback(logger, SUN_LOGLEVEL_INFO, NULL, NULL, "KINSol",NULL);
+    intermediateCallback(logger, SUN_LOGLEVEL_INFO, NULL, NULL, "KINSol", noargs);
     SUNLogger_Destroy(&logger);
 
     if (m_wstrDisplay != L"none" && m_liExitCode >= 0)
