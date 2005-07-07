--- src/messages/header_alloc.c	Mon Aug 30 13:28:48 2004
+++ src/messages/header_alloc.c	Wed Jul  6 23:39:03 2005
@@ -318,6 +318,38 @@
     }
 
     for (tmphdr = locate_header_by_name(parsed_headers,
+						"Newsgroup");
+	 tmphdr;
+	 tmphdr = tmphdr -> next_this_header) {
+	struct addr_item * addrs =
+	    break_down_address(tmphdr->body,
+			       !(current_header -> status &
+				 NOHDRENCODING) &&
+			       is_rfc1522(tmphdr->body),
+			       current_header->header_charset);
+
+	if (addrs) {
+	    if (current_header->to)
+		free_addr_items(current_header->to);
+	    current_header->to = addrs;
+
+#if DEBUG
+	    if (Debug.active > 10) {
+		struct addr_item * p;
+		for (p =  current_header->to; p->addr; p++) {
+		    DPRINT(Debug,15,(&Debug,
+				     "--   newsgroup[%d] addr='%s' comment='%S' fullname='%S'\n",
+				     p - current_header->to,
+				     p->addr,
+				     p->comment,
+				     p->fullname));
+		}
+	    }
+#endif
+	}
+    }
+
+    for (tmphdr = locate_header_by_name(parsed_headers,
 					"Cc");
 	 tmphdr;
 	 tmphdr = tmphdr -> next_this_header) {
