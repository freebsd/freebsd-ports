--- panel-plugin/network.cc.orig	2022-02-16 18:57:05 UTC
+++ panel-plugin/network.cc
@@ -39,7 +39,7 @@ static gint
 #include <glibtop/netload.h>
 
 static gint
-read_netload_libgtop (gulong *bytes)
+read_netload_libgtop (guint64 *bytes)
 {
     glibtop_netlist netlist;
     char **interfaces = glibtop_get_netlist (&netlist);
@@ -60,7 +60,7 @@ static gint
 #else
 
 static gint
-read_netload_libgtop (gulong *bytes)
+read_netload_libgtop (guint64 *bytes)
 {
     return -1;
 }
@@ -70,7 +70,7 @@ static gint
 static const char *const PROC_NET_NETSTAT = "/proc/net/netstat";
 
 static gint
-read_netload_proc (gulong *bytes)
+read_netload_proc (guint64 *bytes)
 {
     char buf[4*1024];
     unsigned long long dummy, in_octets, out_octets;
