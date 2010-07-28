--- ./lib/ipmi_fru.c.orig	2009-02-25 15:38:52.000000000 -0500
+++ ./lib/ipmi_fru.c	2010-07-23 14:46:07.000000000 -0400
@@ -489,7 +489,8 @@
 	struct ipmi_rq req;
 	uint8_t msg_data[25];
 	uint8_t writeLength;
-   uint16_t num_bloc;
+   	uint16_t num_bloc;
+	t_ipmi_fru_bloc * fru_bloc;
 
 	finish = doffset + length;			 /* destination offset */
 	if (finish > fru->size)
@@ -498,7 +499,7 @@
 		return -1;
 	}
 
-   t_ipmi_fru_bloc * fru_bloc = build_fru_bloc(intf, fru, id, &num_bloc);
+	fru_bloc = build_fru_bloc(intf, fru, id, &num_bloc);
 
 	memset(&req, 0, sizeof(req));
 	req.msg.netfn = IPMI_NETFN_STORAGE;
