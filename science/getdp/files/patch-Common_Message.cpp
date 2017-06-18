--- Common/Message.cpp.orig	2017-06-17 23:49:49 UTC
+++ Common/Message.cpp
@@ -124,7 +124,7 @@ void Message::Initialize(int argc, char 
   std::vector<wchar_t*> wargv(argc ? argc : 1);
   for(int i = 0; i < argc; i++)
     wargv[i] = Py_DecodeLocale(argv[i], NULL);
-  Py_SetProgramName(wargv[0], NULL);
+  Py_SetProgramName(wargv[0]);
   Py_InitializeEx(0);
   PySys_SetArgv(argc, &wargv[0]);
 #endif
