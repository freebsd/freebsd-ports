Index: src/sysdeps/bsd-common.c
diff -u src/sysdeps/bsd-common.c.orig src/sysdeps/bsd-common.c
--- src/sysdeps/bsd-common.c.orig	Sun Oct 13 12:26:29 2002
+++ src/sysdeps/bsd-common.c	Fri Jan  3 19:15:29 2003
@@ -22,6 +22,45 @@
 |  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
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
+gkrellm_sys_net_read_data(void)
+	{
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
+			ifd = (struct if_data *)ifa->ifa_data;
+			gkrellm_net_assign_data(ifa->ifa_name,
+					ifd->ifi_ibytes, ifd->ifi_obytes);
+			}
+		}
+
+	freeifaddrs(ifap);
+	}
+
+#else /* HAVE_GETIFADDRS */
+
 #include <sys/sysctl.h>
 #include <sys/socket.h> // For PF_ROUTE, etc
 #include <net/if.h>
@@ -86,6 +125,8 @@
 			}
 		}
 	}
+
+#endif /* HAVE_GETIFADDRS */
 
   /* This would be needed only if net up (or routed) state is available in
   |  a different way than for reading net stats.
