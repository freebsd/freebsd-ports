--- vdetaplib/test.c	Sat Jan 29 15:02:08 2005
+++ vdetaplib/test.c	Sun Jan 30 12:27:35 2005
@@ -6,35 +6,28 @@
 #include <errno.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/types.h>
 #include <sys/ioctl.h>
+#include <sys/socket.h>
 #include <net/if.h>
-#include <linux/if_tun.h>
+#include <net/if_tun.h>
 
 static int tun_alloc(char *dev)
 {
-	struct ifreq ifr;
+	struct ifstat ifs;
 	int fd, err;
 
-	if( (fd = open("/dev/net/tun", O_RDWR)) < 0 )
+	if( (fd = open("/dev/tap", O_RDWR)) < 0 )
 		return (-1);
 
-	memset(&ifr, 0, sizeof(ifr));
+	memset(&ifs, 0, sizeof(ifs));
 
-	/* Flags: IFF_TUN   - TUN device (no Ethernet headers) 
-	 *        IFF_TAP   - TAP device  
-	 *
-	 *        IFF_NO_PI - Do not provide packet information  
-	 */ 
-	ifr.ifr_flags = IFF_TAP; 
-	if( *dev )
-		strncpy(ifr.ifr_name, dev, IFNAMSIZ);
-
-	if( (err = ioctl(fd, TUNSETIFF, (void *) &ifr)) < 0 ){
+	if( (err = ioctl(fd, SIOCGIFSTATUS, (void *) &ifs)) < 0 ){
 		close(fd);
 		return err;
 	}
 	printf("ioctl returns\n");
-	strcpy(dev, ifr.ifr_name);
+	puts(ifs.ascii);
 	printf("ioctl idev\n");
 	return fd;
 }              
