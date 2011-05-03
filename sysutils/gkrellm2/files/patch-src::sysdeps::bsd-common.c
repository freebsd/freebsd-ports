Index: src/sysdeps/bsd-common.c
diff -u -p src/sysdeps/bsd-common.c.orig src/sysdeps/bsd-common.c
--- src/sysdeps/bsd-common.c.orig	2010-09-15 01:27:35.000000000 +0900
+++ src/sysdeps/bsd-common.c	2011-05-04 02:20:07.328745551 +0900
@@ -64,6 +64,10 @@ gkrellm_sys_net_read_data(void)
 			{
 			if (ifa->ifa_addr->sa_family != AF_LINK)
 				continue;
+#ifdef IFF_CANTCONFIG
+			if ((ifa->ifa_flags & IFF_CANTCONFIG) != 0)
+				continue;
+#endif
 			ifd = (struct if_data *)ifa->ifa_data;
 			gkrellm_net_assign_data(ifa->ifa_name,
 					ifd->ifi_ibytes, ifd->ifi_obytes);
