--- server/access.c.orig	2018-04-30 09:19:08 UTC
+++ server/access.c
@@ -11,6 +11,10 @@ static char	sccsid[] = "@(#)$Id: access.
 #endif
 #include <sys/socket.h>
 
+#ifdef __FreeBSD__
+# include <netdb.h>
+#endif
+
 #define	SNETMATCH	1
 #define	NETMATCH	2
 
@@ -40,6 +44,12 @@ static char	sccsid[] = "@(#)$Id: access.
  *	Side effects:	None.
  */
 
+typedef union {
+  struct sockaddr sa;
+  struct sockaddr_in sin;
+  struct sockaddr_in6 sin6;
+} nntp_sockaddr_union_t;
+
 #ifdef EXCELAN
 extern struct sockaddr_in current_peer;
 #endif
@@ -60,8 +70,7 @@ host_access(hcanread, hcanpost, hcanxfer
 {
 	int		sockt;
 	socklen_t	length;
-	struct sockaddr	sa;
-	struct sockaddr_in *sin = (struct sockaddr_in *) &sa;
+	nntp_sockaddr_union_t	su;
 #ifdef TLI
 	struct hostent	*hp;
 	int		argcnt = 0;
@@ -89,10 +98,11 @@ host_access(hcanread, hcanpost, hcanxfer
 	*hcanread = *hcanpost = *hcanxfer = 0;
 
 	sockt = fileno(stdin);
-	length = sizeof (sa);
+	length = sizeof (su);
+	int sa_len = (su.sa.sa_family == AF_INET) ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
 
 #ifdef TLI
-	if (t_getpeername(sockt, &sa, &length) < 0) {
+	if (t_getpeername(sockt, &su.sa, &length) < 0) {
 		if (isatty(sockt)) {
 			(void) strcpy(hostname, "stdin");
 			*hcanread = 1;
@@ -110,7 +120,7 @@ host_access(hcanread, hcanpost, hcanxfer
 #ifdef EXCELAN
 	if (raddr(current_peer.sin_addr) == NULL) {
 #else
-	if (getpeername(sockt, &sa, &length) < 0) {
+	if (getpeername(sockt, &su.sa, &length) < 0) {
 #endif
 		if (isatty(sockt)) {
 			(void) strcpy(hostname, "stdin");
@@ -124,24 +134,35 @@ host_access(hcanread, hcanpost, hcanxfer
 		return;
 	}
 #ifdef EXCELAN
-	else bcopy(&current_peer,&sa,length);
+	else bcopy(&current_peer,&su.sa,length);
 #endif
 #endif /* !TLI */
 
-	switch (sa.sa_family) {
+	switch (su.sa.sa_family) {
 	case AF_INET:
-		inet_netnames(sockt, sin, net_name, snet_name, host_name);
+		inet_netnames(sockt, &su.sin, net_name, snet_name, host_name);
 		break;
 
+	case AF_INET6:
+
+		getnameinfo( (struct sockaddr *) &su.sa, su.sa.sa_len, 
+			     host_name, sizeof(host_name), NULL, 0, 0 );
+		net_name[0] = snet_name[0] = '\0';
+#ifdef SYSLOG
+		syslog(LOG_DEBUG, "IPv6 connect from %s (%ld->%d/%d)",
+			host_name, sizeof(su.sa), length, su.sa.sa_len );
+#endif
+               break;
+
 #ifdef DECNET
 	case AF_DECnet:
-		dnet_netnames(sockt, &sa, net_name, snet_name, host_name);
+		dnet_netnames(sockt, &su.sa, net_name, snet_name, host_name);
 		break;
 #endif
 
 	default:
 #ifdef SYSLOG
-		syslog(LOG_ERR, "unknown address family %ld", (long)(sa.sa_family));
+		syslog(LOG_ERR, "unknown address family %ld", (long)(su.sa.sa_family));
 #endif
 		return;
 	};
