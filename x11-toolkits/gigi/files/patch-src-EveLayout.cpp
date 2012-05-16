--- src/EveLayout.cpp.orig	2012-01-27 19:11:18.000000000 +0300
+++ src/EveLayout.cpp	2012-01-27 19:14:31.000000000 +0300
@@ -1815,7 +1815,7 @@
 #endif
 
             m_evaluator.evaluate(view_params.m_parameters);
-            adobe::dictionary_t parameters(move(m_evaluator.back().cast<adobe::dictionary_t>()));
+            adobe::dictionary_t parameters(::adobe::move(m_evaluator.back().cast<adobe::dictionary_t>()));
             m_evaluator.pop_back();
 
 #if INSTRUMENT_WINDOW_CREATION
