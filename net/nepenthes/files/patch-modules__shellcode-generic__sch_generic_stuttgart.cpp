--- modules/shellcode-generic/sch_generic_stuttgart.cpp.orig
+++ modules/shellcode-generic/sch_generic_stuttgart.cpp
@@ -27,6 +27,8 @@
 
  /* $Id: sch_generic_link_trans.cpp 1664 2005-07-15 03:33:39Z common $ */
  
+#include <cstdio>
+#include <cstring>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
