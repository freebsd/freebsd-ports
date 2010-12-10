--- avidemux/ADM_core/src/ADM_crashdump.cpp.orig
+++ avidemux/ADM_core/src/ADM_crashdump.cpp
@@ -47,7 +47,7 @@ void ADM_setCrashHook(ADM_saveFunction *
 extern char *ADM_getBaseDir(void);
 extern void A_parseECMAScript(const char *name);
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 void installSigHandler() {}
 
 void ADM_backTrack(const char *info,int lineno,const char *file)
