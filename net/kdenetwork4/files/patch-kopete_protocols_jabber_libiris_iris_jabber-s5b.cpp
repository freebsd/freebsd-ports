--- kopete/protocols/jabber/libiris/iris/jabber/s5b.cpp.orig	Tue Dec 20 06:12:48 2005
+++ kopete/protocols/jabber/libiris/iris/jabber/s5b.cpp	Tue Dec 20 06:19:39 2005
@@ -18,6 +18,8 @@
  *
  */
 
+#include <config.h>
+
 #include"s5b.h"
 
 #include<qtimer.h>
@@ -32,6 +34,9 @@
 #ifdef Q_OS_WIN
 # include <windows.h>
 #else
+# ifdef HAVE_SYS_TYPES_H
+#  include <sys/types.h>
+# endif
 # include <netinet/in.h>
 #endif
 
