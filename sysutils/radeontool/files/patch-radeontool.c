--- ../radeontool-1.5/radeontool.c	Wed Feb 11 12:50:27 2004
+++ radeontool.c	Thu Aug 18 23:53:15 2005
@@ -21,7 +21,13 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/mman.h>
+#include <getopt.h>
+#ifdef __LINUX__
 #include <asm/page.h>
+#elif __FreeBSD__
+#include <machine/param.h>
+#include <sys/pciio.h>
+#endif
 
 #include "radeon_reg.h"
 
@@ -233,6 +239,7 @@
 }
 
 
+#ifdef __LINUX__
 /* Here we fork() and exec() the lspci command to look for the Radeon hardware address. */
 static void map_radeon_cntl_mem(void)
 {
@@ -318,13 +325,76 @@
         printf("Radeon found. Base control address is %x.\n",base);
     radeon_cntl_mem = map_devince_memory(base,0x2000);
 }
+#endif
 
-int main(int argc,char *argv[]) 
+#ifdef __FreeBSD__
+#define MAX_RADEON_CARDS 10
+static void map_radeon_cntl_mem(void)
 {
-    if(argc == 1) {
-        map_radeon_cntl_mem();
-	usage();
+    int fd ;
+    struct pci_conf_io pci;
+    struct pci_match_conf pmc;
+    struct pci_conf pc[MAX_RADEON_CARDS];
+    struct pci_io pi;
+    
+    pmc.pc_vendor = 0x1002;/*ATI*/
+    pmc.pc_class = 0x3; /*Display*/
+    pci.offset =0;
+    pmc.flags = PCI_GETCONF_MATCH_VENDOR|PCI_GETCONF_MATCH_CLASS;
+    pci.pat_buf_len = sizeof(pmc);
+    pci.num_patterns = 1;
+    pci.patterns =&pmc;
+    pci.match_buf_len = sizeof(pc);
+    pci.num_matches=0;
+    pci.matches = pc;
+
+    if(skip >= MAX_RADEON_CARDS ){
+        fprintf(stderr,"I cannot handle cards so much\n");
+	exit(-1);
+    }
+
+    fd = open("/dev/pci", O_RDWR);
+    if(fd == -1){
+        perror("open");
+	exit(-1);
+    }
+
+    if(ioctl(fd, PCIOCGETCONF, &pci) == -1){
+        perror("PCIOCGETCONF");
+	exit(-1);
+    }
+
+    if(pci.num_matches == 0){
+        fprintf(stderr, "Cannot found devices\n");
+	exit(-1);
+    }
+
+    if(pci.num_matches < skip ){
+        fprintf(stderr, "There are not so much ATI cards\n");
+	exit(-1);
+    }
+
+    pi.pi_sel = pc[skip].pc_sel;
+    pi.pi_reg = 0x18;
+    pi.pi_width = 4;
+    if(ioctl(fd, PCIOCREAD, &pi) == -1){
+        perror("PCIOCREAD");
+	exit(-1);
     }
+    
+    if(pi.pi_data &1){
+        fprintf(stderr, "Not memory mapped\n");
+	exit(-1);
+    }
+
+    radeon_cntl_mem = map_devince_memory(pi.pi_data&0xfffffff0,0x2000);
+}
+
+#endif
+
+int main(int argc,char *argv[]) 
+{
+#if 0
     if(strcmp(argv[1],"--debug") == 0) {
         debug=1;
         argv++; argc--;
@@ -333,6 +403,33 @@
         skip=atoi(argv[1]+7);
         argv++; argc--;
     };
+#else
+    int ch;
+    static struct option longopts [] = {
+      {"debug", no_argument, NULL, 'd'},
+      {"skip", required_argument, NULL, 's'},
+      {NULL, 0, NULL, 0}
+    }; 
+    while((ch = getopt_long(argc, argv, "ds:", longopts, NULL)) != -1){
+      switch(ch){
+      case 'd':
+	debug = 1;
+	break;
+      case 's':
+	skip=atoi(optarg);
+	break;
+      default:
+	usage();
+      }
+    }
+    optind --;
+    argc -= optind;
+    argv += optind;
+#endif
+    if(argc == 1) {
+        map_radeon_cntl_mem();
+	usage();
+    }
     map_radeon_cntl_mem();
     if(argc == 2) {
         if(strcmp(argv[1],"regs") == 0) {
