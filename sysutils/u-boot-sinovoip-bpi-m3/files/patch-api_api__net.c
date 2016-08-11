--- api/api_net.c.orig	2016-04-12 02:22:25 UTC
+++ api/api_net.c
@@ -25,7 +25,7 @@ DECLARE_GLOBAL_DATA_PTR;
 
 #define errf(fmt, args...) do { printf("ERROR @ %s(): ", __func__); printf(fmt, ##args); } while (0)
 
-#ifdef CONFIG_CMD_NET
+#if defined(CONFIG_CMD_NET) && !defined(CONFIG_DM_ETH)
 
 static int dev_valid_net(void *cookie)
 {
