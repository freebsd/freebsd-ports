--- src/utils/Environment.cpp.orig	2022-04-22 18:54:13 UTC
+++ src/utils/Environment.cpp
@@ -122,7 +122,7 @@ void Environment::setMsgFilePath()
   string_t lang="en";
   if (theLanguage_ != 0) lang=languageString();
 #ifdef OS_IS_UNIX
-  thePathToMessageFiles_ = installPath() + "/etc/messages/" + lang + "/";
+  thePathToMessageFiles_ = installPath() + "/share/xlife++/messages/" + lang + "/";
 #elif defined(OS_IS_WIN)
   thePathToMessageFiles_ = installPath() + "\\etc\\messages\\" + lang + "\\";
 #endif
