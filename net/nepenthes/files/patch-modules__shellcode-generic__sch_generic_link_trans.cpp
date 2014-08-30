--- modules/shellcode-generic/sch_generic_link_trans.cpp.orig
+++ modules/shellcode-generic/sch_generic_link_trans.cpp
@@ -28,6 +28,8 @@
  /* $Id: sch_generic_link_trans.cpp 2271 2006-01-14 20:31:52Z common $ */
 
 
+#include <cstdio>
+#include <cstring>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
