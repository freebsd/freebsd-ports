--- lib/efi_loader/efi_net.c.orig	2016-11-14 16:27:11 UTC
+++ lib/efi_loader/efi_net.c
@@ -27,7 +27,8 @@ struct efi_net_obj {
 	struct efi_simple_network net;
 	struct efi_simple_network_mode net_mode;
 	/* Device path to the network adapter */
-	struct efi_device_path_file_path dp[2];
+	struct efi_device_path_mac_addr dp_mac;
+	struct efi_device_path_file_path dp_end;
 	/* PXE struct to transmit dhcp data */
 	struct efi_pxe pxe;
 	struct efi_pxe_mode pxe_mode;
@@ -205,7 +206,7 @@ static efi_status_t EFIAPI efi_net_open_
 	struct efi_simple_network *net = handle;
 	struct efi_net_obj *netobj = container_of(net, struct efi_net_obj, net);
 
-	*protocol_interface = netobj->dp;
+	*protocol_interface = &netobj->dp_mac;
 
 	return EFI_SUCCESS;
 }
@@ -236,11 +237,10 @@ void efi_net_set_dhcp_ack(void *pkt, int
 int efi_net_register(void **handle)
 {
 	struct efi_net_obj *netobj;
-	struct efi_device_path_file_path dp_net = {
-		.dp.type = DEVICE_PATH_TYPE_MEDIA_DEVICE,
-		.dp.sub_type = DEVICE_PATH_SUB_TYPE_FILE_PATH,
+	struct efi_device_path_mac_addr dp_net = {
+		.dp.type = DEVICE_PATH_TYPE_MESSAGING_DEVICE,
+		.dp.sub_type = DEVICE_PATH_SUB_TYPE_MSG_MAC_ADDR,
 		.dp.length = sizeof(dp_net),
-		.str = { 'N', 'e', 't' },
 	};
 	struct efi_device_path_file_path dp_end = {
 		.dp.type = DEVICE_PATH_TYPE_END,
@@ -279,8 +279,9 @@ int efi_net_register(void **handle)
 	netobj->net.receive = efi_net_receive;
 	netobj->net.mode = &netobj->net_mode;
 	netobj->net_mode.state = EFI_NETWORK_STARTED;
-	netobj->dp[0] = dp_net;
-	netobj->dp[1] = dp_end;
+	netobj->dp_mac = dp_net;
+	netobj->dp_end = dp_end;
+	memcpy(netobj->dp_mac.mac.addr, eth_get_ethaddr(), 6);
 	memcpy(netobj->net_mode.current_address.mac_addr, eth_get_ethaddr(), 6);
 	netobj->net_mode.max_packet_size = PKTSIZE;
 
