--- source/abrEncApp.cpp	2020-05-29 13:39:35.000000000 -0400
+++ source/abrEncApp.cpp	2020-07-19 17:37:32.365958000 -0400
@@ -815,5 +815,5 @@
             if (m_param->csvfn && !b_ctrl_c)
 #if ENABLE_LIBVMAF
-                api->vmaf_encoder_log(m_encoder, m_cliopt.argCount, m_cliopt.argString, m_cliopt.param, vmafdata);
+                api->vmaf_encoder_log(m_encoder, m_cliopt.argCnt, m_cliopt.argString, m_cliopt.param, vmafdata);
 #else
                 api->encoder_log(m_encoder, m_cliopt.argCnt, m_cliopt.argString);
