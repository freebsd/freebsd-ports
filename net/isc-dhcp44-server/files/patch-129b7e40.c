diff --git a/RELNOTES b/RELNOTES
index 9d0a04144253e399d572e043ff2f4da4613d9b82..6919dba7f7e8fc91269081115648f4da3636a153 100644
--- RELNOTES
+++ RELNOTES
@@ -103,6 +103,11 @@ ISC DHCP is open source software maintained by Internet Systems
 Consortium.  This product includes cryptographic software written
 by Eric Young (eay@cryptsoft.com).
 
+		Changes since 4.4.2 (Bug Fixes)
+
+- Minor corrections to allow compilation under gcc 10.
+  [Gitlab #117]
+
 		Changes since 4.4.2b1 (Bug Fixes)
 
 - Added a clarification on DHCPINFORMs and server authority to
diff --git a/client/dhclient.c b/client/dhclient.c
index 189e527094e8adaaa71c4bb859e484018168b100..7a7837cb8152796743a4c9aeec55ceb413c1cde6 100644
--- client/dhclient.c
+++ client/dhclient.c
@@ -83,8 +83,9 @@ static const char message [] = "Internet Systems Consortium DHCP Client";
 static const char url [] = "For info, please visit https://www.isc.org/software/dhcp/";
 #endif /* UNIT_TEST */
 
-u_int16_t local_port = 0;
-u_int16_t remote_port = 0;
+extern u_int16_t local_port;
+extern u_int16_t remote_port;
+
 #if defined(DHCPv6) && defined(DHCP4o6)
 int dhcp4o6_state = -1; /* -1 = stopped, 0 = polling, 1 = started */
 #endif
diff --git a/common/discover.c b/common/discover.c
index ca4f4d55ec9f06c8217222787add5e413b206627..22f09767e98079c8d95ed1e8cb5dd00b56158da4 100644
--- common/discover.c
+++ common/discover.c
@@ -45,8 +45,8 @@ struct interface_info *fallback_interface = 0;
 
 int interfaces_invalidated;
 int quiet_interface_discovery;
-u_int16_t local_port;
-u_int16_t remote_port;
+u_int16_t local_port = 0;
+u_int16_t remote_port = 0;
 u_int16_t relay_port = 0;
 int dhcpv4_over_dhcpv6 = 0;
 int (*dhcp_interface_setup_hook) (struct interface_info *, struct iaddr *);
diff --git a/relay/dhcrelay.c b/relay/dhcrelay.c
index 883d5058f2ee5b95ea7a23e6cd4c95b41ff08b9c..7211e3bbbec937386c0f5335a626a35dca8fee72 100644
--- relay/dhcrelay.c
+++ relay/dhcrelay.c
@@ -95,8 +95,8 @@ enum { forward_and_append,	/* Forward and append our own relay option. */
        forward_untouched,	/* Forward without changes. */
        discard } agent_relay_mode = forward_and_replace;
 
-u_int16_t local_port;
-u_int16_t remote_port;
+extern u_int16_t local_port;
+extern u_int16_t remote_port;
 
 /* Relay agent server list. */
 struct server_list {
diff --git a/server/mdb.c b/server/mdb.c
index ff8a707fac1b82e0bd00f9cc1f0730be6d18e43e..8266d76432b8fd1fa3ccedb29c75dc68107ae25a 100644
--- server/mdb.c
+++ server/mdb.c
@@ -67,7 +67,7 @@ static host_id_info_t *host_id_info = NULL;
 
 int numclasseswritten;
 
-omapi_object_type_t *dhcp_type_host;
+extern omapi_object_type_t *dhcp_type_host;
 
 isc_result_t enter_class(cd, dynamicp, commit)
 	struct class *cd;
diff --git a/server/mdb6.c b/server/mdb6.c
index da7baf6e50dfb6c92d8c2d3f9229f8a06f6c61a2..ebe01e5607cb57e7385f739470b82416a43a5b2e 100644
--- server/mdb6.c
+++ server/mdb6.c
@@ -1945,7 +1945,7 @@ create_prefix6(struct ipv6_pool *pool, struct iasubopt **pref,
 		}
 		new_ds.data = new_ds.buffer->data;
 		memcpy(new_ds.buffer->data, ds.data, ds.len);
-		memcpy(new_ds.buffer->data + ds.len, &tmp, sizeof(tmp));
+		memcpy(&new_ds.buffer->data[0] + ds.len, &tmp, sizeof(tmp));
 		data_string_forget(&ds, MDL);
 		data_string_copy(&ds, &new_ds, MDL);
 		data_string_forget(&new_ds, MDL);
