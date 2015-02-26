--- ./lib/apputils/net-server.c.orig	2015-02-24 14:19:36.000000000 -0800
+++ ./lib/apputils/net-server.c	2015-02-25 16:57:05.339001826 -0800
@@ -1038,8 +1038,12 @@
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
