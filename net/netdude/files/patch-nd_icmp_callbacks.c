--- protocols/icmp/nd_icmp_callbacks.c.orig	Fri Sep 20 02:40:51 2002
+++ protocols/icmp/nd_icmp_callbacks.c	Sun Oct 13 20:52:27 2002
@@ -63,7 +63,7 @@
 
   struct icmphdr *icmphdr = (struct icmphdr *) header;
   
-  switch (icmphdr->type)
+  switch (icmphdr->icmp_type)
     {
     case ICMP_DEST_UNREACH:
       if (!unreach_menu)
@@ -82,7 +82,7 @@
   
   nd_dialog_number(_("Enter ICMP code:"),
 		   ND_BASE_DEC,
-		   icmphdr->code,
+		   icmphdr->icmp_code,
 		   255,
 		   (ND_NumberCallback) nd_icmp_code_value_cb,
 		   NULL,
@@ -107,7 +107,7 @@
       if (!icmphdr)
 	continue;
   
-      icmphdr->checksum = htons(value);
+      icmphdr->icmp_cksum = htons(value);
       nd_packet_modified_at_index(nd_pit_get(&pit), nd_pit_get_index(&pit));
     }
 
@@ -125,7 +125,7 @@
 
   nd_dialog_number(_("Enter ICMP checksum:"),
 		   ND_BASE_HEX,
-		   ntohs(icmphdr->checksum), 65535,
+		   ntohs(icmphdr->icmp_cksum), 65535,
 		   icmp_sum_ok_cb,
 		   NULL,
 		   packet, data);
@@ -145,7 +145,7 @@
       if (!icmphdr)
 	continue;
   
-      switch (icmphdr->type)
+      switch (icmphdr->icmp_type)
 	{
 	case ICMP_ECHO:
 	case ICMP_ECHOREPLY:
@@ -161,7 +161,7 @@
 	  continue;
 	}
 
-      icmphdr->un.echo.id = htons(value);
+      icmphdr->icmp_id = htons(value);
       nd_packet_modified_at_index(nd_pit_get(&pit), nd_pit_get_index(&pit));
     }
 
@@ -179,7 +179,7 @@
 
   nd_dialog_number(_("Enter ICMP identifier:"),
 		   ND_BASE_DEC,
-		   ntohs(icmphdr->un.echo.id),
+		   ntohs(icmphdr->icmp_id),
 		   65535,
 		   (ND_NumberCallback) icmp_id_ok_cb,
 		   NULL,
@@ -202,7 +202,7 @@
       if (!icmphdr)
 	continue;
 
-      switch (icmphdr->type)
+      switch (icmphdr->icmp_type)
 	{
 	case ICMP_ECHO:
 	case ICMP_ECHOREPLY:
@@ -218,7 +218,7 @@
 	  continue;
 	}
   
-      icmphdr->un.echo.sequence = htons(value);
+      icmphdr->icmp_seq = htons(value);
       nd_packet_modified_at_index(nd_pit_get(&pit), nd_pit_get_index(&pit));
     }
 
@@ -236,7 +236,7 @@
 
   nd_dialog_number(_("Enter ICMP sequence number:"),
 		   ND_BASE_DEC,
-		   ntohs(icmphdr->un.echo.sequence),
+		   ntohs(icmphdr->icmp_seq),
 		   65535,
 		   (ND_NumberCallback) icmp_seq_ok_cb,
 		   NULL,
@@ -425,7 +425,7 @@
       if (!icmphdr)
 	continue;
   
-      icmphdr->un.gateway = htonl(value);
+      icmphdr->icmp_gwaddr.s_addr = htonl(value);
       nd_packet_modified_at_index(nd_pit_get(&pit), nd_pit_get_index(&pit));
     }
 
@@ -441,12 +441,12 @@
 {
   struct icmphdr *icmphdr = (struct icmphdr *) header;
 
-  if (!nd_icmp_header_is_error(icmphdr) && icmphdr->type != 10)
+  if (!nd_icmp_header_is_error(icmphdr) && icmphdr->icmp_type != 10)
     return;
 
   nd_dialog_number(_("Enter 32-bit ICMP data:"),
 		   ND_BASE_DEC,
-		   ntohl(icmphdr->un.gateway), (guint) -1,
+		   ntohl(icmphdr->icmp_gwaddr.s_addr), (guint) -1,
 		   icmp_error_ok_cb,
 		   NULL, packet, data);    
 }
@@ -589,7 +589,7 @@
 	continue;
   
       icmphdr = (struct icmphdr *) data;
-      if (icmphdr->type != 9)
+      if (icmphdr->icmp_type != 9)
 	continue;
 
       memcpy(data + 8 + entry_num * 8, address, sizeof(guchar) * 4);
@@ -634,7 +634,7 @@
 	continue;
   
       icmphdr = (struct icmphdr *) data;
-      if (icmphdr->type != 9)
+      if (icmphdr->icmp_type != 9)
 	continue;
       
       memcpy(data + 12 + entry_num * 8, &val, sizeof(guint32));
@@ -684,7 +684,7 @@
       if (!icmphdr)
 	continue;
   
-      icmphdr->type = value;
+      icmphdr->icmp_type = value;
       nd_packet_init(packet);
       nd_packet_modified_at_index(nd_pit_get(&pit), nd_pit_get_index(&pit));
     }
@@ -703,7 +703,7 @@
 
   nd_dialog_number(_("Enter ICMP type:"),
 		   ND_BASE_DEC,
-		   icmphdr->type,
+		   icmphdr->icmp_type,
 		   255,
 		   (ND_NumberCallback) nd_icmp_type_value_cb,
 		   NULL,
@@ -728,7 +728,7 @@
       if (!icmphdr)
 	continue;
   
-      icmphdr->code = value;
+      icmphdr->icmp_code = value;
       nd_packet_modified_at_index(nd_pit_get(&pit), nd_pit_get_index(&pit));
     }
 
@@ -746,7 +746,7 @@
 
   nd_dialog_number(_("Enter ICMP code:"),
 		   ND_BASE_DEC,
-		   icmphdr->code,
+		   icmphdr->icmp_code,
 		   255,
 		   (ND_NumberCallback) nd_icmp_code_value_cb,
 		   NULL,
@@ -774,7 +774,7 @@
       
       if (!nd_icmp_csum_correct(nd_pit_get(&pit), &correct_sum))
 	{
-	  icmphdr->checksum = correct_sum;
+	  icmphdr->icmp_cksum = correct_sum;
 	  nd_packet_modified_at_index(nd_pit_get(&pit), nd_pit_get_index(&pit));
 	}
     }
