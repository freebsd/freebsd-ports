--- rtpsend.c.orig	2016-06-20 15:59:04 UTC
+++ rtpsend.c
@@ -354,9 +354,9 @@ static int rtcp_rr(node_t *list, char *p
       if (strcmp(n->type, "ssrc") == 0)
         rr->ssrc = htonl(n->num);
       else if (strcmp(n->type, "fraction") == 0)
-        rr->fraction = (n->num)*256;
-      else if (strcmp(n->type, "lost") == 0)   /* PP: alignment OK? */
-        rr->lost = htonl(n->num);
+        rr->fraclost = htonl((ntohl(rr->fraclost) & 0x00ffffff) | ((n->num)*256 << 24));
+      else if (strcmp(n->type, "lost") == 0)
+	rr->fraclost = htonl((ntohl(rr->fraclost) & 0xff000000) | n->num);
       else if (strcmp(n->type, "last_seq") == 0)
         rr->last_seq = htonl(n->num);
       else if (strcmp(n->type, "jit") == 0)
@@ -926,6 +926,8 @@ int main(int argc, char *argv[])
       local = (struct in_addr *)host->h_addr_list[0];
       sin.sin_addr = *local;
     }
+  } else {
+    usage(argv[0]);
   }
 
   /* create/connect sockets */
