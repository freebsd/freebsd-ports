--- types.h	Sat Feb 23 17:28:00 2002
+++ types.h	Tue Mar 26 18:19:00 2002
@@ -1,6 +1,8 @@
 /* types.h - tpyes needed in sendip and not defined everywhere
  * Author: Mike Ricketts <mike@earth.li>
  * ChangeLog since 2.1 release:
+ * 03/02/2002 Added more defines/protos for non-IPv6 systems.
+ * 26/03/2002 FreeBSD style BYTE_ORDER fixes
  */
 #ifndef _SENDIP_TYPES_H
 #define _SENDIP_TYPES_H
@@ -25,8 +27,13 @@
 
 /* for things that *really* don't know about ipv6, ... */
 #ifndef AF_INET6
-#define PF_INET6 10
-#define AF_INET6 PF_INET6
+#define AF_INET6 10
+#define IPPROTO_ICMPV6 58
+#define IPPROTO_NONE 59
+#define IPPROTO_DSTOPTS 60
+#endif /* !AF_INET6 */
+
+#ifndef s6_addr
 struct in6_addr {
 	union {
 		u_int8_t  u6_addr8[16];
@@ -37,6 +44,8 @@
 #define s6_add16 in6_u.u6_addr16
 #define s6_add32 in6_u.u6_addr32
 };
+extern const struct in6_addr in6addr_any;        /* :: */
+extern const struct in6_addr in6addr_loopback;   /* ::1 */
 
 struct sockaddr_in6 {
 	u_int16_t sin6_family;
@@ -45,8 +54,9 @@
 	struct in6_addr sin6_addr;
 	u_int32_t sin6_scope_id;
 };
+extern int inet_pton (int af, const char *cp, void *buf);
 
-#endif /* !AF_INET 6 */
+#endif /* !s6_addr */
 
 /* Convert _BIG_ENDIAN/_LITTLE_ENDIAN to __BYTE_ORDER */
 #ifndef __LITTLE_ENDIAN
@@ -58,15 +68,30 @@
 #endif
 
 #ifndef __BYTE_ORDER
+
+/* Not linux-style, maybe FreeBSD-style */
+#ifdef BYTE_ORDER
+#undef __LITTLE_ENDIAN
+#undef __BIG_ENDIAN
+#define __LITTLE_ENDIAN LITTLE_ENDIAN
+#define __BIG_ENDIAN BIG_ENDIAN
+#define __BYTE_ORDER BYTE_ORDER
+#else
+
+/* Not FreeBSD-style, try solaris style */
 #ifdef _BIG_ENDIAN
 #define __BYTE_ORDER __BIG_ENDIAN
 #else   /* not _BIG_ENDIAN */
 #ifdef _LITTLE_ENDIAN
 #define __BYTE_ORDER __LITTLE_ENDIAN
 #else   /* not _LITTLE_ENDIAN */
+
+/* Not solaris style.  Give up. */
 #error Could not guess your byte order
+
 #endif  /* not _LITTLE_ENDIAN */
 #endif  /* not _BIG_ENDIAN */
-#endif  /* _BYTE_ORDER */
+#endif  /* not BYTE_ORDER */
+#endif  /* not __BYTE_ORDER */
 
 #endif  /* _SENDIP_TYPES_H */
