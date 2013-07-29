--- api/api.c.orig	2013-04-19 09:25:43.000000000 -0500
+++ api/api.c	2013-05-16 17:04:11.000000000 -0500
@@ -226,8 +226,8 @@
 		debugf("RESTART ENUM\n");
 
 		/* net device enumeration first */
-		if (dev_enum_net(di))
-			return 0;
+		//if (dev_enum_net(di))
+		//return 0;
 	}
 
 	/*
@@ -264,8 +264,8 @@
 	if (di->type & DEV_TYP_STOR)
 		err = dev_open_stor(di->cookie);
 
-	else if (di->type & DEV_TYP_NET)
-		err = dev_open_net(di->cookie);
+	//	else if (di->type & DEV_TYP_NET)
+	//		err = dev_open_net(di->cookie);
 	else
 		err = API_ENODEV;
 
@@ -295,8 +295,8 @@
 	if (di->type & DEV_TYP_STOR)
 		err = dev_close_stor(di->cookie);
 
-	else if (di->type & DEV_TYP_NET)
-		err = dev_close_net(di->cookie);
+	//	else if (di->type & DEV_TYP_NET)
+	//		err = dev_close_net(di->cookie);
 	else
 		/*
 		 * In case of unknown device we cannot change its state, so
@@ -364,8 +364,8 @@
 		 */
 		return API_ENODEV;
 
-	else if (di->type & DEV_TYP_NET)
-		err = dev_write_net(di->cookie, buf, *len);
+	//	else if (di->type & DEV_TYP_NET)
+	//		err = dev_write_net(di->cookie, buf, *len);
 	else
 		err = API_ENODEV;
 
@@ -436,6 +436,7 @@
 
 		*act_len_stor = dev_read_stor(di->cookie, buf, *len_stor, *start);
 
+#if 0
 	} else if (di->type & DEV_TYP_NET) {
 
 		/* 3. arg points to the var with length of packet to read */
@@ -452,6 +453,7 @@
 
 		*act_len_net = dev_read_net(di->cookie, buf, *len_net);
 
+#endif
 	} else
 		return API_ENODEV;
 
