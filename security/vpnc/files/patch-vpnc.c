--- vpnc.c.dist	Mon May  3 14:13:05 2004
+++ vpnc.c	Mon May  3 14:13:41 2004
@@ -1527,10 +1527,10 @@
 	  reject = ISAKMP_N_ATTRIBUTES_NOT_SUPPORTED;
 	  break;
 	}
-	strbuf = xallocc(a->u.lots.length)+1;
+	strbuf = xallocc(a->u.lots.length+1);
 	memcpy(strbuf, a->u.lots.data, a->u.lots.length);
 	addenv("CISCO_DEF_DOMAIN", strbuf);
-	/*free(strbuf); free(): invalid pointer 0x80593f9! FIXME */
+	free(strbuf);
 	break;
 	
       case ISAKMP_MODECFG_ATTRIB_CISCO_BANNER:
@@ -1538,7 +1538,7 @@
 	  reject = ISAKMP_N_ATTRIBUTES_NOT_SUPPORTED;
 	  break;
 	}
-	strbuf = xallocc(a->u.lots.length)+1;
+	strbuf = xallocc(a->u.lots.length+1);
 	memcpy(strbuf, a->u.lots.data, a->u.lots.length);
 	addenv("CISCO_BANNER", strbuf);
 	free(strbuf);
@@ -2162,8 +2162,8 @@
     else
       read_config_file (argv[i], config, 0);
 
-  read_config_file ("/etc/vpnc/default.conf", config, 1);
-  read_config_file ("/etc/vpnc.conf", config, 1);
+  read_config_file ("%%PREFIX%%/etc/vpnc/default.conf", config, 1);
+  read_config_file ("%%PREFIX%%/etc/vpnc.conf", config, 1);
 
   if (!print_config) {
     if (!config[CONFIG_IKE_DH])
