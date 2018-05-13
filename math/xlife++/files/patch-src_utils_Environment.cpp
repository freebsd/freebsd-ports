--- src/utils/Environment.cpp.orig	2018-05-13 04:01:14 UTC
+++ src/utils/Environment.cpp
@@ -121,7 +121,7 @@ void Environment::processor()
 void Environment::setMsgFilePath()
 {
 #ifdef OS_IS_UNIX
-  thePathToMessageFiles_ = installPath() + "/etc/messages/" + languageString() + "/";
+  thePathToMessageFiles_ = installPath() + "/share/xlife++/messages/" + languageString() + "/";
 #elif defined(OS_IS_WIN)
   thePathToMessageFiles_ = installPath() + "\\etc\\messages\\" + languageString() + "\\";
 #endif
