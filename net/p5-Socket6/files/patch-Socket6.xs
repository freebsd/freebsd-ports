Index: Socket6.xs
diff -u Socket6.xs.orig Socket6.xs
--- Socket6.xs.orig	Sun Aug 28 01:53:11 2005
+++ Socket6.xs	Thu Jul  5 19:31:29 2007
@@ -59,9 +59,14 @@
 #include <sys/socket.h>
 #include <netinet/in.h>
 #ifdef __KAME__
+# include <sys/param.h>
 # include <net/route.h>
-# ifndef __OpenBSD__
-#  include <netinet6/ipsec.h>
+# if defined(__FreeBSD__) && __FreeBSD_version >= 700048
+#  include <netipsec/ipsec.h>
+# else
+#  ifndef __OpenBSD__
+#   include <netinet6/ipsec.h>
+#  endif
 # endif
 #endif
 #include <netdb.h>
