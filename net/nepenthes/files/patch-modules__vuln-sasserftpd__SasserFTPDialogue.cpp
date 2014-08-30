--- modules/vuln-sasserftpd/SasserFTPDDialogue.cpp.orig
+++ modules/vuln-sasserftpd/SasserFTPDDialogue.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: SasserFTPDDialogue.cpp 836 2007-02-06 15:16:50Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstring>
 
 #include "SasserFTPDDialogue.hpp"
 #include "vuln-sasserftpd.hpp"
