diff --git a/security/krb5/files/patch-lib__apputils__net-server.c b/security/krb5/files/patch-lib__apputils__net-server.c
new file mode 100644
index 0000000..01d0298
--- /dev/null
+++ b/security/krb5/files/patch-lib__apputils__net-server.c
@@ -0,0 +1,28 @@
+--- ./lib/apputils/net-server.c.orig	2014-04-17 08:07:05.144912855 +0000
++++ ./lib/apputils/net-server.c	2014-04-17 08:07:59.603908167 +0000
+@@ -992,8 +992,12 @@
+     case RTM_NEWADDR: return "RTM_NEWADDR";
+     case RTM_DELADDR: return "RTM_DELADDR";
+     case RTM_IFINFO: return "RTM_IFINFO";
++#ifdef RTM_OLDADD
+     case RTM_OLDADD: return "RTM_OLDADD";
++#endif
++#ifdef RTM_OLDDEL
+     case RTM_OLDDEL: return "RTM_OLDDEL";
++#endif
+     case RTM_RESOLVE: return "RTM_RESOLVE";
+ #ifdef RTM_NEWMADDR
+     case RTM_NEWMADDR: return "RTM_NEWMADDR";
+@@ -1026,8 +1030,12 @@
+     case RTM_NEWADDR:
+     case RTM_DELADDR:
+     case RTM_IFINFO:
++#ifdef RTM_OLDADD
+     case RTM_OLDADD:
++#endif
++#ifdef RTM_OLDDEL
+     case RTM_OLDDEL:
++#endif
+         /*
+          * Some flags indicate routing table updates that don't
+          * indicate local address changes.  They may come from
