--- src/network/udp.c.orig	2018-01-17 13:29:46 UTC
+++ src/network/udp.c
@@ -315,7 +315,7 @@ net_SourceSubscribe (vlc_object_t *obj, 
 {
 /* MCAST_JOIN_SOURCE_GROUP was introduced to OS X in v10.7, but it doesn't work,
  * so ignore it to use the same code path as on 10.5 or 10.6 */
-#if defined (MCAST_JOIN_SOURCE_GROUP) && !defined (__APPLE__)
+#if defined (MCAST_JOIN_SOURCE_GROUP) && !defined (__APPLE__) && !defined (__FreeBSD__)
     /* Family-agnostic Source-Specific Multicast join */
     int level;
     struct group_source_req gsr;
