Index: src/net.c
diff -u src/net.c.orig src/net.c
--- src/net.c.orig	Mon Jul  1 11:17:27 2002
+++ src/net.c	Fri Jan  3 19:11:51 2003
@@ -120,10 +120,6 @@
 
 /* -------- FreeBSD / NetBSD / OpenBSD ------------------------------------ */
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
-#include <sys/sysctl.h>
-#include <net/if.h>
-#include <net/if_dl.h>
-#include <net/route.h>
 
 #define	LOCK_DIRECTORY		"/var/spool/lock"
 
@@ -133,6 +129,107 @@
 	{"ppp0", TIMER_TYPE_PPP }
 	};
 
+#if !(defined(__FreeBSD__) && __FreeBSD_version < 410000) && \
+    !(defined(__NetBSD__) && __NetBSD_version < 105000000) && \
+    !(defined(__OpenBSD__) && OpenBSD < 200006)
+#define HAVE_GETIFADDRS	1
+#endif
+
+#if defined(HAVE_GETIFADDRS)
+
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <net/if.h>
+#include <ifaddrs.h>
+
+void
+read_bsd_net_data()
+	{
+	GList			*list;
+	NetMon			*net;
+	struct ifaddrs		*ifap, *ifa;
+	struct if_data		*ifd;
+
+	if (getifaddrs(&ifap) < 0)
+		return;
+
+	for (ifa = ifap; ifa; ifa = ifa->ifa_next)
+		{
+		if (ifa->ifa_flags & IFF_UP)
+			{
+			if (ifa->ifa_addr->sa_family != AF_LINK)
+				continue;
+			for (list = net_mon_list; list; list = list->next)
+				{
+				net = (NetMon *) list->data;
+				if (strcmp(net->name, ifa->ifa_name) == 0)
+					{
+					ifd = (struct if_data *)ifa->ifa_data;
+					net->rx = ifd->ifi_ibytes;
+					net->tx = ifd->ifi_obytes;
+					net->rxtx_units = NET_UNITS_BYTES;
+					break;
+					}
+				}
+			}
+		}
+
+	freeifaddrs(ifap);
+	}
+
+static void
+sync_bsd_net_interfaces()
+	{
+	GList			*list;
+	NetMon			*net;
+	struct ifaddrs		*ifap, *ifa;
+
+	for (list = net_mon_list; list; list = list->next)
+		{
+		net = (NetMon *) list->data;
+		net->old_state = net->state;
+		net->state = NET_DOWN;
+		}
+
+	if (getifaddrs(&ifap) < 0)
+		return;
+
+	for (ifa = ifap; ifa; ifa = ifa->ifa_next)
+		{
+		if (ifa->ifa_flags & IFF_UP)
+			{
+			if (ifa->ifa_addr->sa_family != AF_LINK)
+				continue;
+			for (list = net_mon_list; list; list = list->next)
+				{
+				net = (NetMon *) list->data;
+				if (strcmp(net->name, ifa->ifa_name) == 0)
+					{
+					net->state = NET_UP;
+					break;
+					}
+				}
+			if (list == NULL)
+				{
+				net = g_new0(NetMon, 1);
+				net->name = g_strdup(ifa->ifa_name);
+				net_mon_list = g_list_append(net_mon_list, net);
+				net->state = NET_UP;
+				net->old_state = NET_DOWN;
+				}
+			}
+		}
+
+	freeifaddrs(ifap);
+	}
+
+#else /* HAVE_GETIFADDRS */
+
+#include <sys/sysctl.h>
+#include <net/if.h>
+#include <net/if_dl.h>
+#include <net/route.h>
+
 static int	mib[] = { CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST, 0 };
 static char	*buf;
 static int	alloc;
@@ -289,6 +386,8 @@
 			}
 		}
 	}
+
+#endif /* HAVE_GETIFADDRS */
 #endif
 
 
