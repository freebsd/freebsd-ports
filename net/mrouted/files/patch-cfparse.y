--- cfparse.y.orig	1998-03-01 07:48:58.000000000 +0600
+++ cfparse.y	2008-03-30 20:52:40.000000000 +0700
@@ -4,6 +4,7 @@
  *
  * Written by Bill Fenner, NRL, 1994
  *
+ * $FreeBSD: /tmp/pcvs/ports/net/mrouted/files/Attic/patch-cfparse.y,v 1.1 2008-03-31 10:13:37 bms Exp $
  * cfparse.y,v 3.8.4.30 1998/03/01 01:48:58 fenner Exp
  */
 #include <stdio.h>
@@ -14,17 +15,18 @@
 #endif
 #include "defs.h"
 #include <netdb.h>
+#include <ifaddrs.h>
 
 /*
  * Local function declarations
  */
-static void		fatal __P((char *fmt, ...));
-static void		warn __P((char *fmt, ...));
+static void		fatal __P((char *fmt, ...)) __printflike(1, 2);
+static void		warn __P((char *fmt, ...)) __printflike(1, 2);
 static void		yyerror __P((char *s));
 static char *		next_word __P((void));
 static int		yylex __P((void));
 static u_int32		valid_if __P((char *s));
-static struct ifreq *	ifconfaddr __P((struct ifconf *ifcp, u_int32 a));
+static const char *	ifconfaddr(u_int32_t a);
 int			yyparse __P((void));
 
 static FILE *f;
@@ -34,9 +36,6 @@
 extern int cache_lifetime;
 extern int prune_lifetime;
 
-/* imported from config.c, with slight memory leak */
-extern struct ifconf ifc;
-
 int allow_black_holes = 0;
 
 static int lineno;
@@ -127,15 +126,14 @@
 					}
 		ifmods
 	| TUNNEL interface addrname	{
-
-			struct ifreq *ifr;
+			const char *ifname;
 			struct ifreq ffr;
 			vifi_t vifi;
 
 			order++;
 
-			ifr = ifconfaddr(&ifc, $2);
-			if (ifr == 0)
+			ifname = ifconfaddr($2);
+			if (ifname == 0)
 			    fatal("Tunnel local address %s is not mine",
 				inet_fmt($2, s1));
 
@@ -144,7 +142,7 @@
 			    fatal("Tunnel local address %s is a loopback address",
 				inet_fmt($2, s1));
 
-			if (ifconfaddr(&ifc, $3) != 0)
+			if (ifconfaddr($3) != 0)
 			    fatal("Tunnel remote address %s is one of mine",
 				inet_fmt($3, s1));
 
@@ -164,7 +162,7 @@
 			if (numvifs == MAXVIFS)
 			    fatal("too many vifs");
 
-			strncpy(ffr.ifr_name, ifr->ifr_name, IFNAMSIZ);
+			strlcpy(ffr.ifr_name, ifname, sizeof(ffr.ifr_name));
 			if (ioctl(udp_socket, SIOCGIFFLAGS, (char *)&ffr)<0)
 			    fatal("ioctl SIOCGIFFLAGS on %s", ffr.ifr_name);
 
@@ -175,7 +173,7 @@
 			v->uv_lcl_addr	= $2;
 			v->uv_rmt_addr	= $3;
 			v->uv_dst_addr	= $3;
-			strncpy(v->uv_name, ffr.ifr_name, IFNAMSIZ);
+			strlcpy(v->uv_name, ffr.ifr_name, sizeof(v->uv_name));
 
 			if (!(ffr.ifr_flags & IFF_UP)) {
 			    v->uv_flags |= VIFF_DOWN;
@@ -577,7 +575,8 @@
 addrname	: ADDR		{ $$ = $1; }
 	| STRING		{ struct hostent *hp;
 
-				  if ((hp = gethostbyname($1)) == NULL)
+				  if ((hp = gethostbyname($1)) == NULL ||
+					hp->h_length != sizeof($$))
 				    fatal("No such host %s", $1);
 
 				  if (hp->h_addr_list[1])
@@ -655,7 +654,7 @@
 fatal(char *fmt, ...)
 {
 	va_list ap;
-	char buf[200];
+	char buf[MAXHOSTNAMELEN + 100];
 
 	va_start(ap, fmt);
 #else
@@ -666,11 +665,11 @@
 va_dcl
 {
 	va_list ap;
-	char buf[200];
+	char buf[MAXHOSTNAMELEN + 100];
 
 	va_start(ap);
 #endif
-	vsprintf(buf, fmt, ap);
+	vsnprintf(buf, sizeof(buf), fmt, ap);
 	va_end(ap);
 
 	log(LOG_ERR,0,"%s: %s near line %d", configfilename, buf, lineno);
@@ -696,7 +695,7 @@
 
 	va_start(ap);
 #endif
-	vsprintf(buf, fmt, ap);
+	vsnprintf(buf, sizeof(buf), fmt, ap);
 	va_end(ap);
 
 	log(LOG_WARNING,0,"%s: %s near line %d", configfilename, buf, lineno);
@@ -902,28 +901,24 @@
 	return 0;
 }
 
-static struct ifreq *
-ifconfaddr(ifcp, a)
-    struct ifconf *ifcp;
-    u_int32 a;
-{
-    int n;
-    struct ifreq *ifrp = (struct ifreq *)ifcp->ifc_buf;
-    struct ifreq *ifend = (struct ifreq *)((char *)ifrp + ifcp->ifc_len);
-
-    while (ifrp < ifend) {
-	    if (ifrp->ifr_addr.sa_family == AF_INET &&
-		((struct sockaddr_in *)&ifrp->ifr_addr)->sin_addr.s_addr == a)
-		    return (ifrp);
-#ifdef HAVE_SA_LEN
-		n = ifrp->ifr_addr.sa_len + sizeof(ifrp->ifr_name);
-		if (n < sizeof(*ifrp))
-			++ifrp;
-		else
-			ifrp = (struct ifreq *)((char *)ifrp + n);
-#else
-		++ifrp;
-#endif
+static const char *
+ifconfaddr(u_int32_t a)
+{
+    static char ifname[IFNAMSIZ];
+    struct ifaddrs *ifap, *ifa;
+
+    if (getifaddrs(&ifap) != 0)
+	return (NULL);
+
+    for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
+	if (ifa->ifa_addr->sa_family == AF_INET &&
+	    ((struct sockaddr_in *)ifa->ifa_addr)->sin_addr.s_addr == a) {
+	    strlcpy(ifname, ifa->ifa_name, sizeof(ifname));
+	    freeifaddrs(ifap);
+	    return (ifname);
+	}
     }
-    return (0);
+
+    freeifaddrs(ifap);
+    return (NULL);
 }
