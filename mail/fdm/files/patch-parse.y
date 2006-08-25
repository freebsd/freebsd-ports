--- ./parse.y.orig	Fri Aug 25 16:42:22 2006
+++ ./parse.y	Fri Aug 25 16:42:32 2006
@@ -21,6 +21,7 @@
 %{
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/limits.h>
 
 #include <ctype.h>
 #include <grp.h>
