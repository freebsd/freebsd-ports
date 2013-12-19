--- drivers.c.orig	Tue Apr 27 09:22:02 2004
+++ drivers.c	Tue Apr 27 09:32:19 2004
@@ -21,7 +21,7 @@
 #include"config.h"
 
 
-/* For FreeBSD */
+/* For OpenBSD */
 #ifdef USE_KVM
 #include<net/if.h>
 #include<kvm.h>
@@ -37,6 +37,22 @@
 int kvm_updateStats(void);
 #endif /* USE_KVM */
 
+#ifdef USE_SYSCTL
+/* system headers */
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/socket.h>
+#include <net/if.h>
+#include <net/if_mib.h>
+#include <sys/errno.h>
+
+int id = 0; /* interface id */
+size_t len = 0; /* sizeof libmibdata */
+struct ifmibdata *data = NULL;
+
+int sysctl_test(void);
+int sysctl_updateStats(void);
+#endif
 
 #ifdef USE_LINUX_PPP
 #include<net/ppp_defs.h>
@@ -104,12 +120,15 @@
 #ifdef USE_KVM
  {"kmem",kvm_updateStats, kvm_test},
 #endif
+#ifdef USE_SYSCTL
+ {"sysctl",sysctl_updateStats, sysctl_test},
+#endif
  {NULL, NULL}
 };
 
 char* available_drivers(void) {
  int ind = 0;
- int len = 0;
+ size_t len = 0;
  char *string, *ptr;
  while(drivers[ind].name != NULL) {
   len += strlen(drivers[ind].name) + 1;
@@ -440,6 +459,115 @@
 
 #endif /* linux */
 
+/* new FreeBSD driver */
+#ifdef USE_SYSCTL
+
+int sysctl_test(void) {
+  struct ifmibdata tempndata;
+  int numifaces;
+  size_t len2;
+  int mib[5], datamib[6];
+  int i;
+
+  if(device == NULL) device = "lo0";
+  
+  mib[0] = CTL_NET;
+  mib[1] = PF_LINK;
+  mib[2] = NETLINK_GENERIC;
+  mib[3] = IFMIB_SYSTEM;
+  mib[4] = IFMIB_IFCOUNT;
+         
+  datamib[0] = CTL_NET;
+  datamib[1] = PF_LINK;
+  datamib[2] = NETLINK_GENERIC;
+  datamib[3] = IFMIB_IFDATA;
+  datamib[4] = 1; 
+  datamib[5] = IFDATA_GENERAL;
+
+  len = sizeof(struct ifmibdata); 
+  len2 = sizeof(numifaces);
+
+  if(sysctl(mib, 5, &numifaces, &len2, NULL, 0) < 0)
+  {
+    fprintf( stderr, "wmnet: failed to perform sysctl" );
+    return 0;
+  }
+
+  for(i = 1; i <= numifaces; i++)
+  {
+    datamib[4] = i;
+    if(sysctl(datamib, 6, &tempndata, &len, NULL, 0) < 0)
+    {
+      fprintf( stderr, "wmnet: failed to get device(%d) data", i );
+      break;
+    }
+
+    if( strcmp( device, tempndata.ifmd_name ) == 0 )
+    {
+      id = i;
+      break;
+    }
+  }
+  
+  if ( id == 0 ) {
+    fprintf( stderr, "%s doesn't seem to exist!\n", device );
+    exit( -1 );
+  }
+
+  /* calculate and allocate mem for ifmibdata containing the if stats */ 
+  data = malloc(len);
+
+  fprintf(stderr, "wmnet: using sysctl driver to monitor %s\n", device);
+  return True;
+}
+
+int sysctl_updateStats(void) {
+  int datamib[6];
+
+  datamib[0] = CTL_NET;
+  datamib[1] = PF_LINK;
+  datamib[2] = NETLINK_GENERIC;
+  datamib[3] = IFMIB_IFDATA;
+  datamib[4] = id;
+  datamib[5] = IFDATA_GENERAL;
+
+  if(sysctl( datamib, 6, data, &len, NULL, 0) < 0 ) {
+    fprintf( stderr, "wmnet: can't monitor %s device\n", device );
+    exit( -1 );  
+  }
+
+  //  printf( "if name: %s\n", data->ifmd_name );  
+
+  /* get the stats from the if */
+  totalpackets_in = data->ifmd_data.ifi_ipackets;
+  totalpackets_out = data->ifmd_data.ifi_opackets;
+
+  if (totalpackets_in != lastpackets_in) {
+    totalbytes_in = data->ifmd_data.ifi_ibytes;
+    diffpackets_in += totalpackets_in - lastpackets_in;
+    diffbytes_in += totalbytes_in - lastbytes_in;
+    lastpackets_in = totalpackets_in;
+    lastbytes_in = totalbytes_in;
+    rx = True;
+  } else rx = False;
+  
+  if (totalpackets_out != lastpackets_out) {
+    totalbytes_out = data->ifmd_data.ifi_obytes;
+    diffpackets_out += totalpackets_out - lastpackets_out;
+    diffbytes_out += totalbytes_out - lastbytes_out;
+    lastpackets_out = totalpackets_out;
+    lastbytes_out = totalbytes_out;
+    tx = True;
+  } else tx = False;
+  
+  /* return True if no change to tx/rx
+   * return False if display will need to be updated
+   */	 
+  return((rx == current_rx) && (tx == current_tx));
+}
+
+#endif
+
 #ifdef USE_KVM
 int kvm_test(void) {
   if (((kvmfd = kvm_open(NULL, NULL, NULL, O_RDONLY, buffer)) == NULL) ||
