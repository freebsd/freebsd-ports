--- src/network/udp.c.orig
+++ src/network/udp.c
@@ -383,7 +383,7 @@ int net_Subscribe (vlc_object_t *obj, in
 {
 /* MCAST_JOIN_GROUP was introduced to OS X in v10.7, but it doesn't work,
  * so ignore it to use the same code as on 10.5 or 10.6 */
-#if defined (MCAST_JOIN_GROUP) && !defined (__APPLE__)
+#if defined (MCAST_JOIN_GROUP) && !defined (__APPLE__) && !defined (__FreeBSD__)
     /* Agnostic SSM multicast join */
     int level;
     struct group_req gr;
