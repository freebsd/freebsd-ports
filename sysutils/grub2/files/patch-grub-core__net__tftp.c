--- ./grub-core/net/tftp.c.orig	2012-06-23 00:42:07.000000000 +0900
+++ ./grub-core/net/tftp.c	2012-12-21 15:18:49.000000000 +0900
@@ -143,7 +143,7 @@
 
   tftph_ack = (struct tftphdr *) nb_ack.data;
   tftph_ack->opcode = grub_cpu_to_be16 (TFTP_ACK);
-  tftph_ack->u.ack.block = block;
+  tftph_ack->u.ack.block = grub_cpu_to_be16 (block);
 
   err = grub_net_send_udp_packet (data->sock, &nb_ack);
   if (err)
@@ -225,7 +225,7 @@
 	    grub_priority_queue_pop (data->pq);
 
 	    if (file->device->net->packs.count < 50)
-	      err = ack (data, tftph->u.data.block);
+	      err = ack (data, data->block + 1);
 	    else
 	      {
 		file->device->net->stall = 1;
