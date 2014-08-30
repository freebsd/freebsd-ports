--- modules/shellemu-winnt/WinNTShellDialogue.cpp.orig
+++ modules/shellemu-winnt/WinNTShellDialogue.cpp
@@ -28,7 +28,8 @@
 /* $Id: WinNTShellDialogue.cpp 2221 2005-12-23 17:01:33Z common $ */ 
 
 //#include <arpa/inet.h>
-#include <errno.h>
+#include <cerrno>
+#include <cstring>
 #include <string>
 
 #include "WinNTShellDialogue.hpp"
