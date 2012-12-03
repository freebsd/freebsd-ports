--- ./src/util.c.orig	2012-12-03 22:11:37.000000000 +0100
+++ ./src/util.c	2012-12-03 22:11:44.000000000 +0100
@@ -966,16 +966,16 @@
 } /* set_rlimit() */
 #endif
 
-/* netmask(28) => 255.255.255.240 (network order) */
-u_int32_t netmask(int m)
-{
-	inline u_int32_t power(u_int32_t x, u_int32_t y)
+static	inline u_int32_t power(u_int32_t x, u_int32_t y)
 	{
 		u_int32_t r = 1;
 		while (y--) r*=x;
 		return r;
 	}
 
+/* netmask(28) => 255.255.255.240 (network order) */
+u_int32_t netmask(int m)
+{
 	if (m < 0)
 		m = 0;
 
