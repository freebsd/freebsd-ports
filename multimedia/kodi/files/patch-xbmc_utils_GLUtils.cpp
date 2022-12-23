--- xbmc/utils/GLUtils.cpp.orig	2022-12-21 00:14:18 UTC
+++ xbmc/utils/GLUtils.cpp
@@ -148,27 +148,27 @@ void _VerifyGLState(const char* szfile, const char* sz
 void LogGraphicsInfo()
 {
 #if defined(HAS_GL) || defined(HAS_GLES)
-  const GLubyte *s;
+  const char *s;
 
-  s = glGetString(GL_VENDOR);
+  s = reinterpret_cast<const char*>(glGetString(GL_VENDOR));
   if (s)
     CLog::Log(LOGINFO, "GL_VENDOR = %s", s);
   else
     CLog::Log(LOGINFO, "GL_VENDOR = NULL");
 
-  s = glGetString(GL_RENDERER);
+  s = reinterpret_cast<const char*>(glGetString(GL_RENDERER));
   if (s)
     CLog::Log(LOGINFO, "GL_RENDERER = %s", s);
   else
     CLog::Log(LOGINFO, "GL_RENDERER = NULL");
 
-  s = glGetString(GL_VERSION);
+  s = reinterpret_cast<const char*>(glGetString(GL_VERSION));
   if (s)
     CLog::Log(LOGINFO, "GL_VERSION = %s", s);
   else
     CLog::Log(LOGINFO, "GL_VERSION = NULL");
 
-  s = glGetString(GL_SHADING_LANGUAGE_VERSION);
+  s = reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION));
   if (s)
     CLog::Log(LOGINFO, "GL_SHADING_LANGUAGE_VERSION = %s", s);
   else
