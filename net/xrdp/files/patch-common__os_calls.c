diff --git common/os_calls.c common/os_calls.c
index 692dc01..7075ee3 100644
--- common/os_calls.c
+++ common/os_calls.c
@@ -2115,8 +2115,12 @@ g_clearenv(void)
 {
 #if defined(_WIN32)
 #else
+#if defined(BSD)
+  environ[0] = 0;
+#else
   environ = 0;
 #endif
+#endif
 }
 
 /*****************************************************************************/
