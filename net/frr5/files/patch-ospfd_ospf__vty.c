--- ospfd/ospf_vty.c.orig	2019-01-08 08:53:23 UTC
+++ ospfd/ospf_vty.c
@@ -3267,7 +3267,7 @@ DEFUN (show_ip_ospf,
 	uint8_t uj = use_json(argc, argv);
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
@@ -3940,7 +3940,7 @@ DEFUN (show_ip_ospf_interface,
 	uint8_t uj = use_json(argc, argv);
 	struct listnode *node = NULL;
 	char *vrf_name = NULL, *intf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0, idx_intf = 0;
@@ -4067,7 +4067,7 @@ DEFUN (show_ip_ospf_interface_traffic,
 	struct ospf *ospf = NULL;
 	struct listnode *node = NULL;
 	char *vrf_name = NULL, *intf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int inst = 0;
 	int idx_vrf = 0, idx_intf = 0;
 	uint8_t uj = use_json(argc, argv);
@@ -4322,7 +4322,7 @@ DEFUN (show_ip_ospf_neighbor,
 	uint8_t uj = use_json(argc, argv);
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
@@ -4535,7 +4535,7 @@ DEFUN (show_ip_ospf_neighbor_all,
 	uint8_t uj = use_json(argc, argv);
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
@@ -5233,7 +5233,7 @@ DEFUN (show_ip_ospf_neighbor_detail,
 	uint8_t uj = use_json(argc, argv);
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
@@ -5422,7 +5422,7 @@ DEFUN (show_ip_ospf_neighbor_detail_all,
 	uint8_t uj = use_json(argc, argv);
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
@@ -6305,7 +6305,7 @@ DEFUN (show_ip_ospf_database_max,
 	struct ospf *ospf = NULL;
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
@@ -6362,7 +6362,7 @@ DEFUN (show_ip_ospf_instance_database,
 	unsigned short instance = 0;
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx = 0;
@@ -6512,7 +6512,7 @@ DEFUN (show_ip_ospf_instance_database_type_adv_router,
 	unsigned short instance = 0;
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx = 0, idx_vrf = 0;
@@ -9299,7 +9299,7 @@ DEFUN (show_ip_ospf_border_routers,
 	struct ospf *ospf = NULL;
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
@@ -9425,7 +9425,7 @@ DEFUN (show_ip_ospf_route,
 	struct ospf *ospf = NULL;
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
