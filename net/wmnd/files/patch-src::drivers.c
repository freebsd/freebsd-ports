--- src/drivers.c.orig	Tue May 22 11:11:25 2001
+++ src/drivers.c	Thu Nov 29 16:29:44 2001
@@ -17,6 +17,117 @@
  * *_term: deallocate name, eventually drvdata and close fds
  */
 
+#ifdef USE_FREEBSD_SYSCTL
+
+/* functions prototypes */
+int freebsd_dev_list(const char *devname, struct Devices *list) {
+    char *devn;
+    struct Devices *ndev;
+    int mib[5], len;
+  int i;
+  struct ifmibdata ifmd; 
+  
+  mib[0]=CTL_NET;
+  mib[1]=PF_LINK;
+  mib[2]=NETLINK_GENERIC;
+  mib[3]=IFMIB_SYSTEM;
+  mib[4]=IFMIB_IFCOUNT;
+
+  len=sizeof(int);
+
+  if (sysctl(mib, 5, &freebsd_interface_count, &len ,NULL, 0)==-1) {perror("systcl failed");exit(-1);}
+  printf("freebsd_interface_count: %d\n",freebsd_interface_count);
+
+    printf("devname: %s\n", devname);  
+    if (devname != NULL) {
+ 	// fill in the Devices structure
+	ndev=malloc(sizeof(struct Devices));
+	list->next=ndev;
+	// name of device
+	devn=strdup(devname);
+	ndev->name=devn;
+	// next Devices field used to create the chain
+	ndev->next=NULL;  
+	// internale driver data
+	ndev->drvdata=NULL;
+	// driver number
+	ndev->drvnum=0;
+	// status indicator (0 online, 1 offline)
+	ndev->online=0;
+	// device activity start
+	ndev->devstart=time(NULL);
+	// end of initialization
+	printf("freebsd_dev_list finished ok!!!\n");
+	return 1;
+    }
+    else { // we don't have a specific interface to monitor, so we must first retrieve the name of all available interfaces
+printf("any interface defined!\n");	
+  
+  len=sizeof(ifmd);
+  
+  for(i=1;i<=freebsd_interface_count;i++) {
+
+  
+    if (get_ifmib_general(i, &ifmd)==-1) {perror("sysctl2");exit(-1);}
+
+ 	// fill in the Devices structure
+	ndev=malloc(sizeof(struct Devices));
+	list->next=ndev;
+	// name of device
+	devn=strdup(ifmd.ifmd_name);
+	ndev->name=devn;
+	// next Devices field used to create the chain
+	ndev->next=NULL;  
+	// internale driver data
+	ndev->drvdata=NULL;
+	// driver number
+	ndev->drvnum=0;
+	// status indicator (0 online, 1 offline)
+	ndev->online=0;
+	// device activity start
+	ndev->devstart=time(NULL);
+	//update the list pointer
+	list=ndev;
+	// end of initialization
+  
+}
+	
+	return 1;
+    }
+}
+
+int freebsd_dev_init(struct Devices *dev) {
+  printf("nothing to do here!\n");
+    return 0;
+}
+
+int freebsd_dev_get(struct Devices *dev, unsigned long *ip, unsigned long *op, unsigned long *ib, unsigned long *ob) {
+  struct ifmibdata ifmd;
+  int i;
+for(i=1;i<=freebsd_interface_count;i++) {
+  if(get_ifmib_general(i, &ifmd)==-1) {perror("systcl3");exit(-1);}
+  //printf("comparing devname: %s with ifmdname: %s\n",dev->name, ifmd.ifmd_name);
+  if(strcmp(dev->name,ifmd.ifmd_name)==0) {
+    //printf("interface name: %s\n",ifmd.ifmd_name);
+    //printf("ipacktes: %ld opackets: %ld\n",ifmd.ifmd_data.ifi_ipackets,ifmd.ifmd_data.ifi_opackets);
+    //printf("ibytes: %ld obytes: %ld\n",ifmd.ifmd_data.ifi_ibytes,ifmd.ifmd_data.ifi_obytes);  
+    //printf("\n");
+    *ip=ifmd.ifmd_data.ifi_ipackets; *op=ifmd.ifmd_data.ifi_opackets;
+    *ib=ifmd.ifmd_data.ifi_ibytes; *ob=ifmd.ifmd_data.ifi_obytes;
+    return 0;
+  }
+} printf("interface %s not found!\n",dev->name); exit(-1); 
+    
+  return 0;
+}
+
+void freebsd_dev_term(struct Devices *dev) {
+      printf("freebsd_dev_term: %s\n",dev->name); 
+      //free(dev);
+}
+
+#endif /*USE_FREESD_SYSCTL*/
+
 #ifdef USE_SOLARIS_FPPPD
 
 /* strioclt is a support function, not previously declared */
