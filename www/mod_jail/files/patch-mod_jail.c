--- ./mod_jail.c.orig	2007-02-15 12:37:06.000000000 +0000
+++ ./mod_jail.c	2008-12-28 15:39:43.000000000 +0000
@@ -130,7 +130,11 @@
     p_jail_cfg_t cfg = (p_jail_cfg_t) ap_pcalloc(p, sizeof(jail_cfg_t));
 
     cfg->jail_scrlevel = 3; /* good default value */
+#if ((__FreeBSD_version >= 800000 && __FreeBSD_version < 800056) || __FreeBSD_version < 701103)
     cfg->jail.version = 0;
+#else
+    cfg->jail.version = JAIL_API_VERSION;
+#endif
     return (void *)cfg;
 }
 	
@@ -190,7 +194,13 @@
     if (!inet_aton(arg, &in)) {
 	return "could not make sense of jail ip address";
     }
+#if ((__FreeBSD_version >= 800000 && __FreeBSD_version < 800056) || __FreeBSD_version < 701103)
     cfg->jail.ip_number = ntohl(in.s_addr);
+#else
+    cfg->jail.ip4s = 1;
+    cfg->jail.ip4 = ap_pcalloc(cmd->pool, sizeof(struct in_addr));
+    cfg->jail.ip4[0].s_addr = in.s_addr;
+#endif
 
     return NULL;
 }
@@ -321,7 +331,11 @@
 	return NULL;
     }
     cfg->jail_scrlevel = 3; /* good default value */
+#if ((__FreeBSD_version >= 800000 && __FreeBSD_version < 800056) || __FreeBSD_version < 701103)
     cfg->jail.version = 0;
+#else
+    cfg->jail.version = JAIL_API_VERSION;
+#endif
     return (void*)cfg;
 }
 	
@@ -378,7 +392,13 @@
     if (!inet_aton(arg, &in)) {
 	return "could not make sense of jail ip address";
     }
+#if ((__FreeBSD_version >= 800000 && __FreeBSD_version < 800056) || __FreeBSD_version < 701103)
     cfg->jail.ip_number = ntohl(in.s_addr);
+#else
+    cfg->jail.ip4s = 1;
+    cfg->jail.ip4 = ap_pcalloc(cmd->pool, sizeof(struct in_addr));
+    cfg->jail.ip4[0].s_addr = in.s_addr;
+#endif
 
     return NULL;
 }
