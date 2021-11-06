--- plugins/fax/fax_spandsp/spandsp_fax.cpp.orig	2013-02-20 02:18:10 UTC
+++ plugins/fax/fax_spandsp/spandsp_fax.cpp
@@ -82,7 +82,7 @@ static PluginCodec_LogFunction LogFunction;
       LogFunction(level, __FILE__, __LINE__, "FaxCodec", strm.str().c_str()); \
     } else (void)0
 
-static void SpanDSP_Message(int level, const char *text)
+static void SpanDSP_Message(void *user_data, int level, const char *text)
 {
   if (*text != '\0' && LogFunction != NULL) {
     if (level >= SPAN_LOG_DEBUG)
@@ -117,7 +117,7 @@ static void SpanDSP_Message(int level, const char *tex
 
 static void InitLogging(logging_state_t * logging, const std::string & tag)
 {
-  span_log_set_message_handler(logging, SpanDSP_Message);
+  span_log_set_message_handler(logging, SpanDSP_Message, NULL);
 
   int level = SPAN_LOG_SHOW_SEVERITY | SPAN_LOG_SHOW_PROTOCOL | SPAN_LOG_DEBUG;
 
@@ -807,7 +807,7 @@ class MyStats : private t30_stats_t (public)
       strm << "-1 (In progress)";
     strm << "\n"
             "Bit Rate=" << stats.bit_rate << "\n"
-            "Encoding=" << stats.encoding << ' ' << CompressionNames[stats.encoding&3] << "\n"
+            "Encoding=" << stats.compression << ' ' << CompressionNames[stats.compression&3] << "\n"
             "Error Correction=" << stats.error_correcting_mode << "\n"
             "Tx Pages=" << (stats.m_receiving ? -1 : stats.pages_tx) << "\n"
             "Rx Pages=" << (stats.m_receiving ? stats.pages_rx : -1) << "\n"
@@ -839,25 +839,27 @@ class FaxTIFF : public FaxSpanDSP
     char            m_phase;
 
   protected:
+    t30_state_t * m_t30State;
+
     FaxTIFF()
       : m_receiving(false)
       , m_stationIdentifer("-")
-      , m_supported_image_sizes(T30_SUPPORT_US_LETTER_LENGTH |
-                                T30_SUPPORT_US_LEGAL_LENGTH |
-                                T30_SUPPORT_UNLIMITED_LENGTH |
-                                T30_SUPPORT_A4_LENGTH |
-                                T30_SUPPORT_B4_LENGTH |
-                                T30_SUPPORT_215MM_WIDTH |
-                                T30_SUPPORT_255MM_WIDTH |
-                                T30_SUPPORT_303MM_WIDTH)
-      , m_supported_resolutions(T30_SUPPORT_STANDARD_RESOLUTION |
-                                T30_SUPPORT_FINE_RESOLUTION |
-                                T30_SUPPORT_SUPERFINE_RESOLUTION |
-                                T30_SUPPORT_R8_RESOLUTION |
-                                T30_SUPPORT_R16_RESOLUTION)
-      , m_supported_compressions(T30_SUPPORT_T4_1D_COMPRESSION |
-                                 T30_SUPPORT_T4_2D_COMPRESSION |
-                                 T30_SUPPORT_T6_COMPRESSION)
+      , m_supported_image_sizes(T4_SUPPORT_LENGTH_US_LETTER |
+                                T4_SUPPORT_LENGTH_US_LEGAL |
+                                T4_SUPPORT_LENGTH_UNLIMITED |
+                                T4_SUPPORT_LENGTH_A4 |
+                                T4_SUPPORT_LENGTH_B4 |
+                                T4_SUPPORT_WIDTH_215MM |
+                                T4_SUPPORT_WIDTH_255MM |
+                                T4_SUPPORT_WIDTH_303MM)
+      , m_supported_resolutions(T4_RESOLUTION_R8_STANDARD |
+                                T4_RESOLUTION_R8_FINE |
+                                T4_RESOLUTION_R8_SUPERFINE |
+                                T4_RESOLUTION_200_400 |
+                                T4_RESOLUTION_400_400)
+      , m_supported_compressions(T4_COMPRESSION_T4_1D |
+                                 T4_COMPRESSION_T4_2D |
+                                 T4_COMPRESSION_T6)
       , m_phase('A')
     {
     }
@@ -932,6 +934,7 @@ class FaxTIFF : public FaxSpanDSP
         PTRACE(3, m_tag << " Set transmit TIFF file to \"" << m_tiffFileName << '"');
       }
 
+      m_t30State = t30state;
       t30_set_phase_b_handler(t30state, PhaseB, this);
       t30_set_phase_d_handler(t30state, PhaseD, this);
       t30_set_phase_e_handler(t30state, PhaseE, this);
@@ -948,7 +951,7 @@ class FaxTIFF : public FaxSpanDSP
 
       t30_set_supported_modems(t30state, m_supported_modems);
       t30_set_supported_image_sizes(t30state, m_supported_image_sizes);
-      t30_set_supported_resolutions(t30state, m_supported_resolutions);
+      t30_set_supported_bilevel_resolutions(t30state, m_supported_resolutions);
       t30_set_supported_compressions(t30state, m_supported_compressions);
       t30_set_ecm_capability(t30state, m_useECM);
 
@@ -983,50 +986,50 @@ class FaxTIFF : public FaxSpanDSP
     bool IsReceiving() const { return m_receiving; }
 
 
-    static int PhaseB(t30_state_t * t30state, void * user_data, int result)
+    static int PhaseB(void * user_data, int result)
     {
       if (user_data != NULL)
-        ((FaxTIFF *)user_data)->PhaseB(t30state, result);
+        ((FaxTIFF *)user_data)->PhaseB(result);
       return T30_ERR_OK;
     }
 
-    static int PhaseD(t30_state_t * t30state, void * user_data, int result)
+    static int PhaseD(void * user_data, int result)
     {
       if (user_data != NULL)
-        ((FaxTIFF *)user_data)->PhaseD(t30state, result);
+        ((FaxTIFF *)user_data)->PhaseD(result);
       return T30_ERR_OK;
     }
 
-    static void PhaseE(t30_state_t * t30state, void * user_data, int result)
+    static void PhaseE(void * user_data, int result)
     {
       if (user_data != NULL)
-        ((FaxTIFF *)user_data)->PhaseE(t30state, result);
+        ((FaxTIFF *)user_data)->PhaseE(result);
     }
 
 
   private:
-    void PhaseB(t30_state_t * t30state, int)
+    void PhaseB(int)
     {
       m_phase = 'B';
       PTRACE(3, m_tag << " SpanDSP entered Phase B:\n"
-             << MyStats(t30state, m_completed, m_receiving, m_phase));
+             << MyStats(this->m_t30State, m_completed, m_receiving, m_phase));
     }
 
-    void PhaseD(t30_state_t * t30state, int)
+    void PhaseD(int)
     {
       m_phase = 'D';
       PTRACE(3, m_tag << " SpanDSP entered Phase D:\n"
-             << MyStats(t30state, m_completed, m_receiving, m_phase));
+             << MyStats(this->m_t30State, m_completed, m_receiving, m_phase));
     }
 
-    void PhaseE(t30_state_t * t30state, int result)
+    void PhaseE(int result)
     {
       if (result >= 0)
         m_completed = true; // Finished, exit codec loops
 
       m_phase = 'E';
       PTRACE(3, m_tag << " SpanDSP entered Phase E:\n"
-             << MyStats(t30state, m_completed, m_receiving, m_phase));
+             << MyStats(this->m_t30State, m_completed, m_receiving, m_phase));
     }
 };
 
