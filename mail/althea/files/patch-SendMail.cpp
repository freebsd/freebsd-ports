--- SendMail.cpp.orig	Wed Jan 23 02:30:15 2002
+++ SendMail.cpp	Mon Jun 24 21:01:22 2002
@@ -3,6 +3,7 @@
 //  -- created 4/11/00  updated 4/11/00
 /////////////////////////////////////////
 
+#include <pthread.h>
 #include "SendMail.h"
 
 extern Althea gAlthea;
