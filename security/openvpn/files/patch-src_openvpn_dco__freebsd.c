--- src/openvpn/dco_freebsd.c.orig	2025-04-02 06:53:10 UTC
+++ src/openvpn/dco_freebsd.c
@@ -72,6 +72,67 @@ sockaddr_to_nvlist(const struct sockaddr *sa)
     return (nvl);
 }
 
+static bool
+nvlist_to_sockaddr(const nvlist_t *nvl, struct sockaddr_storage *ss)
+{
+    if (!nvlist_exists_number(nvl, "af"))
+    {
+        return (false);
+    }
+    if (!nvlist_exists_binary(nvl, "address"))
+    {
+        return (false);
+    }
+    if (!nvlist_exists_number(nvl, "port"))
+    {
+        return (false);
+    }
+
+    ss->ss_family = nvlist_get_number(nvl, "af");
+
+    switch (ss->ss_family)
+    {
+        case AF_INET:
+        {
+            struct sockaddr_in *in = (struct sockaddr_in *)ss;
+            const void *data;
+            size_t len;
+
+            in->sin_len = sizeof(*in);
+            data = nvlist_get_binary(nvl, "address", &len);
+            if (len != sizeof(in->sin_addr))
+	    {
+		return (false);
+	    }
+            memcpy(&in->sin_addr, data, sizeof(in->sin_addr));
+            in->sin_port = nvlist_get_number(nvl, "port");
+            break;
+        }
+
+        case AF_INET6:
+        {
+            struct sockaddr_in6 *in6 = (struct sockaddr_in6 *)ss;
+            const void *data;
+            size_t len;
+
+            in6->sin6_len = sizeof(*in6);
+            data = nvlist_get_binary(nvl, "address", &len);
+            if (len != sizeof(in6->sin6_addr))
+	    {
+		return (false);
+	    }
+            memcpy(&in6->sin6_addr, data, sizeof(in6->sin6_addr));
+            in6->sin6_port = nvlist_get_number(nvl, "port");
+            break;
+        }
+
+        default:
+            return (false);
+    }
+
+    return (true);
+}
+
 int
 dco_new_peer(dco_context_t *dco, unsigned int peerid, int sd,
              struct sockaddr *localaddr, struct sockaddr *remoteaddr,
@@ -570,6 +631,25 @@ dco_do_read(dco_context_t *dco)
         case OVPN_NOTIF_ROTATE_KEY:
             dco->dco_message_type = OVPN_CMD_SWAP_KEYS;
             break;
+
+        case OVPN_NOTIF_FLOAT: {
+            const nvlist_t *address;
+
+            if (!nvlist_exists_nvlist(nvl, "address"))
+            {
+                msg(M_WARN, "Float notification without address");
+                break;
+            }
+
+            address = nvlist_get_nvlist(nvl, "address");
+            if (!nvlist_to_sockaddr(address, &dco->dco_float_peer_ss))
+            {
+                msg(M_WARN, "Failed to parse float notification");
+                break;
+            }
+            dco->dco_message_type = OVPN_CMD_FLOAT_PEER;
+            break;
+        }
 
         default:
             msg(M_WARN, "Unknown kernel notification %d", type);
