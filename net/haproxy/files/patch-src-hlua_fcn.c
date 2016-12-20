--- src/hlua_fcn.c.orig	2016-12-17 13:58:44.786067000 +0300
+++ src/hlua_fcn.c	2016-12-17 13:59:17.551256000 +0300
@@ -39,6 +39,12 @@ static int class_listener_ref;
 
 #define STATS_LEN (MAX((int)ST_F_TOTAL_FIELDS, (int)INF_TOTAL_FIELDS))
 
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#define s6_addr8	__u6_addr.__u6_addr8
+#define s6_addr16	__u6_addr.__u6_addr16
+#define s6_addr32	__u6_addr.__u6_addr32
+#endif
+
 static struct field stats[STATS_LEN];
 
 int hlua_checkboolean(lua_State *L, int index)
