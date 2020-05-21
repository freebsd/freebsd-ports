--- ospfd/ospf_vty.c.orig	2019-01-08 08:29:22 UTC
+++ ospfd/ospf_vty.c
@@ -3244,7 +3244,7 @@ DEFUN (show_ip_ospf,
 	uint8_t uj = use_json(argc, argv);
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
@@ -3917,7 +3917,7 @@ DEFUN (show_ip_ospf_interface,
 	uint8_t uj = use_json(argc, argv);
 	struct listnode *node = NULL;
 	char *vrf_name = NULL, *intf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0, idx_intf = 0;
@@ -4044,7 +4044,7 @@ DEFUN (show_ip_ospf_interface_traffic,
 	struct ospf *ospf = NULL;
 	struct listnode *node = NULL;
 	char *vrf_name = NULL, *intf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int inst = 0;
 	int idx_vrf = 0, idx_intf = 0;
 	uint8_t uj = use_json(argc, argv);
@@ -4299,7 +4299,7 @@ DEFUN (show_ip_ospf_neighbor,
 	uint8_t uj = use_json(argc, argv);
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
@@ -4512,7 +4512,7 @@ DEFUN (show_ip_ospf_neighbor_all,
 	uint8_t uj = use_json(argc, argv);
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
@@ -5213,7 +5213,7 @@ DEFUN (show_ip_ospf_neighbor_detail,
 	uint8_t uj = use_json(argc, argv);
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
@@ -5402,7 +5402,7 @@ DEFUN (show_ip_ospf_neighbor_detail_all,
 	uint8_t uj = use_json(argc, argv);
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
@@ -6285,7 +6285,7 @@ DEFUN (show_ip_ospf_database_max,
 	struct ospf *ospf = NULL;
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
@@ -6342,7 +6342,7 @@ DEFUN (show_ip_ospf_instance_database,
 	unsigned short instance = 0;
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx = 0;
@@ -6492,7 +6492,7 @@ DEFUN (show_ip_ospf_instance_database_type_adv_router,
 	unsigned short instance = 0;
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx = 0, idx_vrf = 0;
@@ -9260,7 +9260,7 @@ DEFUN (show_ip_ospf_border_routers,
 	struct ospf *ospf = NULL;
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
@@ -9386,7 +9386,7 @@ DEFUN (show_ip_ospf_route,
 	struct ospf *ospf = NULL;
 	struct listnode *node = NULL;
 	char *vrf_name = NULL;
-	bool all_vrf = FALSE;
+	bool all_vrf = false;
 	int ret = CMD_SUCCESS;
 	int inst = 0;
 	int idx_vrf = 0;
