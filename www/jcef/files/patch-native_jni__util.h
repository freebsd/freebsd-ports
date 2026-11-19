--- native/jni_util.h.orig	2026-09-08 14:07:06 UTC
+++ native/jni_util.h
@@ -27,7 +27,7 @@ HWND GetHwndOfCanvas(jobject canvas, JNIEnv* env);
 
 #if defined(OS_WIN)
 HWND GetHwndOfCanvas(jobject canvas, JNIEnv* env);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 unsigned long GetDrawableOfCanvas(jobject canvas, JNIEnv* env);
 #endif
 
