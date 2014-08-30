--- modules/shellcode-generic/sch_generic_connect_trans.cpp.orig
+++ modules/shellcode-generic/sch_generic_connect_trans.cpp
@@ -27,6 +27,7 @@
 
  /* $Id: sch_generic_connect_trans.cpp 550 2006-05-04 10:25:35Z common $ */
 
+#include <cstdio>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
