--- tuncfg/tuncfg.c.orig	2006-06-20 16:47:28.000000000 -0300
+++ tuncfg/tuncfg.c	2010-05-23 11:08:53.000000000 -0300
@@ -20,7 +20,7 @@
  *	normally required by a private networking software. Namely -
  *
  *	* creation of tunneling devices; this requires an access to 
- *	  /dev/net/tun file, which _usually_ has 700 access mask
+ *	  /dev/tapXX files, which _usually_ has 700 access mask
  *
  *	* configuration of the tunneling device using ifconfig, which is
  *	  always a root-level operation
@@ -29,7 +29,7 @@
  *	open a listening domain socket /var/run/tuncfg.sock.
  *
  *	Upon accepting the connection on this socket, it will issue an open()
- *	call for /dev/net/tun file (thus instantiating the tunneling device) 
+ *	call for /dev/tapXX file (iterating over first 16 XX values)
  *	and pass obtained FD to the peer process. It will also query and pass
  *	the MAC address of the device to the peer process.
  *
@@ -48,10 +48,12 @@
 #include <sys/un.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
+#include <sys/sysctl.h>
 #include <arpa/inet.h>
 
-#include <linux/if.h>
-#include <linux/if_tun.h>
+#include <net/if.h>
+#include <net/if_dl.h>
+#include <netinet/in.h>
 
 #include <unistd.h>
 #include <errno.h>
@@ -59,6 +61,7 @@
 #include <fcntl.h>
 #include <stdarg.h>
 #include <stdlib.h>
+#include <string.h>
 
 /*
  *
@@ -68,7 +71,7 @@
 
 #define TUNTAP_URL  "http://www.hamachi.cc/tuntap"
 
-#define MAX_CLIENTS 64
+#define MAX_CLIENTS 16
 
 struct context
 {
@@ -90,6 +93,7 @@
 	struct stat st;
 	pid_t pid;
 	int   fd, r, i;
+	int   debug = 0;
 
 	struct context ctx[MAX_CLIENTS];
 	int ctx_n = 0;
@@ -98,18 +102,28 @@
 	if (getuid() != 0)
 		errorf("tuncfg: must be run with superuser permissions\n");
 
-	// lcok
-	fd = open(LOCK_PATH, O_CREAT);
+	//
+	if (argc > 1)
+	{
+		debug = (strcmp(argv[1], "-d") == 0);
+	}
+
+	// lock
+	fd = open(LOCK_PATH, O_CREAT | O_RDWR);
 	if (fd < 0)
 		errorf("tuncfg: cannot open lock file %s -- %s\n",
 			LOCK_PATH, strerror(errno));
 
+	//
 	if (flock(fd, LOCK_EX | LOCK_NB) < 0)
-		errorf("tuncfg: already running\n");
+	{
+		errorf("tuncfg: already running, "
+		       "use 'killall tuncfg; tuncfg' to restart it\n");
+	}
 
 	// check there's /dev/net/tun
-	if (stat("/dev/net/tun", &st) < 0)
-		errorf("tuncfg: cannot stat() /dev/net/tun -- %s\n"
+	if (stat("/dev/tap0", &st) < 0)
+		errorf("tuncfg: cannot stat() /dev/tap0 -- %s\n"
 		       "tuncfg: visit %s for more information\n",
 		       strerror(errno), TUNTAP_URL);
 	
@@ -143,7 +157,7 @@
 			SOCK_PATH, strerror(errno));
 
 	// daemonize
-	if (argc < 2 || strcmp(argv[1], "-d"))
+	if (! debug)
 	{
 		chdir("/");
 
@@ -196,8 +210,13 @@
 		if (FD_ISSET(fd, &fdr))
 		{
 			struct context * p;
-			struct ifreq   ifr;
 			char buf[4+6];
+			int mib[6];
+			size_t len;
+			struct if_msghdr * msg = NULL;
+			struct sockaddr_dl * sa;
+			char dev_name[32];
+			int i;
 			int cli, dev = -1, tmp = -1;
 
 			cli = accept(fd, (void*)&addr, &alen);
@@ -213,48 +232,64 @@
 				goto done;
 			}
 
-			// open tap device
-			dev = open("/dev/net/tun", O_RDWR);
-			printf("tuncfg: open() %d %d\n", dev, errno);
+			// open first available tap device
+			for (i=0; i<MAX_CLIENTS; i++)
+			{
+				snprintf(dev_name, sizeof(dev_name),
+						"/dev/tap%d", i);
+
+				dev = open(dev_name, O_RDWR);
+				printf("tuncfg: open(%s) %d %d\n", 
+						dev_name, dev, errno);
+				if (dev >= 0)
+					break;
+			}
 			if (dev < 0)
 			{
-				r = (0x02 << 24) | errno;
+				r = (0x02 << 24);
 				goto done;
 			}
 
-			// bring it up
-			strcpy(ifr.ifr_name, "ham%d");
-			ifr.ifr_flags = IFF_TAP | IFF_NO_PI;
-			if (ioctl(dev, TUNSETIFF, (ulong)&ifr) < 0)
+			// query mac
+			mib[0] = CTL_NET;
+			mib[1] = AF_ROUTE;
+			mib[2] = 0;
+			mib[3] = AF_LINK;
+			mib[4] = NET_RT_IFLIST;
+			mib[5] = if_nametoindex("tap0");
+
+			if (! mib[5])
 			{
-				printf("tuncfg: ioctl() -1 %d\n", errno);
 				r = (0x03 << 24) | errno;
 				goto done;
 			}
-			printf("tuncfg: ioctl() 0 %s\n", ifr.ifr_name);
 
-			// query mac
-			tmp = socket(AF_INET, SOCK_DGRAM, 0);
-			if (tmp < 0)
+			if (sysctl(mib, 6, NULL, &len, NULL, 0) < 0)
 			{
-				printf("tuncfg: socket(mac) %d\n", errno);
 				r = (0x04 << 24) | errno;
 				goto done;
 			}
-			
-			if (ioctl(tmp, SIOCGIFHWADDR, (ulong)&ifr) < 0)
+
+			msg = malloc(len);
+			if (! msg)
+			{
+				r = (0x05 << 24) | errno;
+				goto done;
+			}
+
+			if (sysctl(mib, 6, msg, &len, NULL, 0) < 0)
 			{
-				printf("tuncfg: ioctl(mac) %d\n", errno);
 				r = (0x05 << 24) | errno;
 				goto done;
 			}
 
-			memcpy(buf+4, &ifr.ifr_hwaddr.sa_data, 6);
+			sa = (void*)(msg + 1);
+			memcpy(buf+4, LLADDR(sa), 6);
 
 			// remember
 			p = &ctx[ctx_n++];
 			p->fd = cli;
-			strncpy(p->dev, ifr.ifr_name, sizeof(p->dev));
+			strncpy(p->dev, dev_name+5, 5);
 
 			r = 0;
 done:
@@ -264,6 +299,7 @@
 				send_with_fd(cli, buf, sizeof(buf), dev); 
 			}
 
+			free(msg);
 			if (tmp != -1)  close(tmp);
 			if (dev != -1)  close(dev);
 			if (r != 0)     close(cli);
@@ -272,7 +308,7 @@
 skip:
 		for (i=0; i<ctx_n; i++)
 		{
-			unsigned long v[2];
+			unsigned int v[2];
 			char cmd[256];
 			
 			if (! FD_ISSET(ctx[i].fd, &fdr))
@@ -295,7 +331,7 @@
 				goto ack;
 			}
 
-			/* v[0] = ham<n>, v[1] = ip, v[2] = mask */
+			/* v[0] = ip, v[1] = mask */
 			if ( (v[0] & 0xff000000) != 0x05000000 ||
 			     (v[1] & 0xff000000) != 0xff000000 )
 			{
@@ -324,9 +360,13 @@
 
 			r = system(cmd);
 			printf("tuncfg: system(%s) %d %d\n", cmd, r, errno);
-
+			if (r != 0)
+			{
+				r = (0x08 << 24) | (r & 0x00ffffff);
+				goto ack;
+			}
 ack:
-			printf("tuncfg: config() %08x", r);
+			printf("tuncfg: config() %08x\n", r);
 			send_with_fd(ctx[i].fd, &r, sizeof(r), -1);
 		}
 	}
@@ -360,4 +400,3 @@
 
 	return sendmsg(fd, &msg, 0);
 }
-
