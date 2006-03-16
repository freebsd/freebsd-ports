
$FreeBSD$

--- rtpsend.c.orig	Tue Sep 10 13:24:10 2002
+++ rtpsend.c	Sat Aug 16 08:58:12 2003
@@ -353,9 +353,9 @@
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
@@ -919,6 +919,8 @@
       local = (struct in_addr *)host->h_addr_list[0];
       sin.sin_addr = *local;
     }
+  } else {
+    usage(argv[0]);
   }
 
   /* create/connect sockets */
