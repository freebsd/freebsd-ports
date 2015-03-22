--- wpa_supplicant/main.c.orig	2015-03-15 17:30:39 UTC
+++ wpa_supplicant/main.c
@@ -173,6 +173,11 @@ int main(int argc, char *argv[])
 
 	wpa_supplicant_fd_workaround(1);
 
+#ifdef CONFIG_DRIVER_NDIS
+	void driver_ndis_init_ops(void);
+	driver_ndis_init_ops();
+#endif /* CONFIG_DRIVER_NDIS */
+
 	for (;;) {
 		c = getopt(argc, argv,
 			   "b:Bc:C:D:de:f:g:G:hi:I:KLm:No:O:p:P:qsTtuvW");
