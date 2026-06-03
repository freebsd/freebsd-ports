# The unpatched version made assumptions about types that don't hold true on 32 bit
# machines. Express the same function in a more portable way.
#
# (The compile error was: symonnet.c:76:9: error: comparison of integers of different signs: 'ssize_t' (aka 'int') and 'u_int32_t' (aka 'unsigned int') [-Werror,-Wsign-compare]"
#
--- symon/symonnet.c.orig	2025-01-03 13:36:33 UTC
+++ symon/symonnet.c
@@ -70,9 +70,11 @@ send_packet(struct mux * mux)
 void
 send_packet(struct mux * mux)
 {
-    if (sendto(mux->symuxsocket, mux->packet.data,
+    ssize_t sent = sendto(mux->symuxsocket, mux->packet.data,
                mux->packet.offset, 0, (struct sockaddr *) & mux->sockaddr,
                SS_LEN(&mux->sockaddr))
+    ;
+    if (sent < 0 || (size_t)sent
         != mux->packet.offset) {
         mux->senderr++;
     }
