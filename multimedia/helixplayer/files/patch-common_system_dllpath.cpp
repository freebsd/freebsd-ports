--- common/system/dllpath.cpp.orig	Sun Jul 25 17:00:35 2004
+++ common/system/dllpath.cpp	Sun Jul 25 17:03:40 2004
@@ -243,7 +243,7 @@
 	    strResultPath += strPathEnvVar;
 	}
 
-#if defined (_AIX) || defined (_LINUX)
+#if defined (_AIX) || defined (_LINUX) || defined (_FREEBSD)
 	{
 	  char *ptr = (char *) ((const char *)strResultPath);
 	  if(putenv(ptr))
@@ -270,7 +270,7 @@
 #if !defined(_MACINTOSH) && !defined(WIN32_PLATFORM_PSPC)
     if(!m_strPathEnvVar.IsEmpty())
     {
-#if defined(_AIX) || defined(_LINUX)
+#if defined(_AIX) || defined(_LINUX) || defined(_FREEBSD)
       char *ptr = (char *)((const char *)m_strPathEnvVar);
 	if(putenv(ptr))
 	    theError = HXR_FAILED;
