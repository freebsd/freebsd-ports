--- lib/apputils/net-server.c.orig	2014-08-11 15:46:27.000000000 -0700
+++ lib/apputils/net-server.c	2014-08-13 05:33:48.913580280 -0700
@@ -992,8 +992,12 @@
     case RTM_NEWADDR: return "RTM_NEWADDR";
     case RTM_DELADDR: return "RTM_DELADDR";
     case RTM_IFINFO: return "RTM_IFINFO";
+#ifdef RTM_OLDADD
     case RTM_OLDADD: return "RTM_OLDADD";
+#endif
+#ifdef RTM_OLDDEL
     case RTM_OLDDEL: return "RTM_OLDDEL";
+#endif
     case RTM_RESOLVE: return "RTM_RESOLVE";
 #ifdef RTM_NEWMADDR
     case RTM_NEWMADDR: return "RTM_NEWMADDR";
