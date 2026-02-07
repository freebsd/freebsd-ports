--- control.c.orig	2002-04-10 20:09:33 UTC
+++ control.c
@@ -16,8 +16,6 @@
 #include <errno.h>
 #include <string.h>
 #include <stdio.h>
-#include <netinet/in.h>
-#include <arpa/inet.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include "l2tp.h"
@@ -1076,7 +1074,7 @@ int control_finish (struct tunnel *t, struct call *c)
     return 0;
 }
 
-inline int check_control (const struct buffer *buf, struct tunnel *t,
+static inline int check_control (const struct buffer *buf, struct tunnel *t,
                           struct call *c)
 {
     /*
@@ -1212,7 +1210,7 @@ inline int check_control (const struct buffer *buf, st
     return 0;
 }
 
-inline int check_payload (struct buffer *buf, struct tunnel *t,
+static inline int check_payload (struct buffer *buf, struct tunnel *t,
                           struct call *c)
 {
     /*
@@ -1318,7 +1316,7 @@ inline int check_payload (struct buffer *buf, struct t
 #endif
     return 0;
 }
-inline int expand_payload (struct buffer *buf, struct tunnel *t,
+static inline int expand_payload (struct buffer *buf, struct tunnel *t,
                            struct call *c)
 {
     /*
@@ -1498,7 +1496,7 @@ void send_zlb (void *data)
     toss (buf);
 }
 
-inline int write_packet (struct buffer *buf, struct tunnel *t, struct call *c,
+static inline int write_packet (struct buffer *buf, struct tunnel *t, struct call *c,
                          int convert)
 {
     /*
@@ -1582,6 +1580,12 @@ inline int write_packet (struct buffer *buf, struct tu
     wbuf[pos++] = e;
     for (x = 0; x < buf->len; x++)
     {
+		// we must at least still have 3 bytes left in the worst case scenario:
+        // 1 for a possible escape, 1 for the value and 1 to end the PPP stream.
+        if(pos >= (sizeof(wbuf) - 4)) {
+            return -EINVAL;
+        }   
+
         e = *((char *) buf->start + x);
         if ((e < 0x20) || (e == PPP_ESCAPE) || (e == PPP_FLAG))
         {
@@ -1657,7 +1661,7 @@ void handle_special (struct buffer *buf, struct call *
     }
 }
 
-inline int handle_packet (struct buffer *buf, struct tunnel *t,
+int handle_packet (struct buffer *buf, struct tunnel *t,
                           struct call *c)
 {
     int res;
