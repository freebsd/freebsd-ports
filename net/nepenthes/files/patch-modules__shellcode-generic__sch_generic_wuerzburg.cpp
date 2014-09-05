--- modules/shellcode-generic/sch_generic_wuerzburg.cpp.orig
+++ modules/shellcode-generic/sch_generic_wuerzburg.cpp
@@ -27,6 +27,8 @@
 
  /* $Id: sch_generic_wuerzburg.cpp 2271 2006-01-14 20:31:52Z common $ */
 
+#include <cstdio>
+#include <cstring>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
