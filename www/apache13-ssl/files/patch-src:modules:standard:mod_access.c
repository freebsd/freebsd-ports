===================================================================
RCS file: /home/cvspublic/apache-1.3/src/modules/standard/mod_access.c,v
retrieving revision 1.46
retrieving revision 1.47
diff -u -r1.46 -r1.47
--- src/modules/standard/mod_access.c	2004/02/20 20:37:40	1.46
+++ src/modules/standard/mod_access.c	2004/03/07 21:47:14	1.47
@@ -39,8 +39,8 @@
     union {
 	char *from;
 	struct {
-	    unsigned long net;
-	    unsigned long mask;
+	    struct in_addr net;
+	    struct in_addr mask;
 	} ip;
     } x;
     enum allowdeny_type type;
@@ -124,14 +124,14 @@
 
     }
     else if ((s = strchr(where, '/'))) {
-	unsigned long mask;
+	struct in_addr mask;
 
 	a->type = T_IP;
 	/* trample on where, we won't be using it any more */
 	*s++ = '\0';
 
 	if (!is_ip(where)
-	    || (a->x.ip.net = ap_inet_addr(where)) == INADDR_NONE) {
+	    || (a->x.ip.net.s_addr = ap_inet_addr(where)) == INADDR_NONE) {
 	    a->type = T_FAIL;
 	    return "syntax error in network portion of network/netmask";
 	}
@@ -143,24 +143,26 @@
 	}
 	/* is it in /a.b.c.d form? */
 	if (strchr(s, '.')) {
-	    mask = ap_inet_addr(s);
-	    if (mask == INADDR_NONE) {
+	    mask.s_addr = ap_inet_addr(s);
+	    if (mask.s_addr == INADDR_NONE) {
 		a->type = T_FAIL;
 		return "syntax error in mask portion of network/netmask";
 	    }
 	}
 	else {
+	    int i;
+
 	    /* assume it's in /nnn form */
-	    mask = atoi(s);
-	    if (mask > 32 || mask <= 0) {
+	    i = atoi(s);
+	    if (i > 32 || i <= 0) {
 		a->type = T_FAIL;
 		return "invalid mask in network/netmask";
 	    }
-	    mask = 0xFFFFFFFFUL << (32 - mask);
-	    mask = htonl(mask);
+	    mask.s_addr = 0xFFFFFFFFUL << (32 - i);
+	    mask.s_addr = htonl(mask.s_addr);
 	}
 	a->x.ip.mask = mask;
-        a->x.ip.net  = (a->x.ip.net & mask);   /* pjr - This fixes PR 4770 */
+        a->x.ip.net.s_addr  = (a->x.ip.net.s_addr & mask.s_addr);   /* pjr - This fixes PR 4770 */
     }
     else if (ap_isdigit(*where) && is_ip(where)) {
 	/* legacy syntax for ip addrs: a.b.c. ==> a.b.c.0/24 for example */
@@ -171,8 +173,8 @@
 	a->type = T_IP;
 	/* parse components */
 	s = where;
-	a->x.ip.net = 0;
-	a->x.ip.mask = 0;
+	a->x.ip.net.s_addr = 0;
+	a->x.ip.mask.s_addr = 0;
 	shift = 24;
 	while (*s) {
 	    t = s;
@@ -191,6 +193,7 @@
 		return "invalid ip address";
 	    }
 	    if (shift < 0) {
+		a->type = T_FAIL;
 		return "invalid ip address, only 4 octets allowed";
 	    }
 	    octet = atoi(s);
@@ -198,13 +201,13 @@
 		a->type = T_FAIL;
 		return "each octet must be between 0 and 255 inclusive";
 	    }
-	    a->x.ip.net |= octet << shift;
-	    a->x.ip.mask |= 0xFFUL << shift;
+	    a->x.ip.net.s_addr |= (unsigned int)octet << shift;
+	    a->x.ip.mask.s_addr |= 0xFFUL << shift;
 	    s = t;
 	    shift -= 8;
 	}
-	a->x.ip.net = ntohl(a->x.ip.net);
-	a->x.ip.mask = ntohl(a->x.ip.mask);
+	a->x.ip.net.s_addr = ntohl(a->x.ip.net.s_addr);
+	a->x.ip.mask.s_addr = ntohl(a->x.ip.mask.s_addr);
     }
     else {
 	a->type = T_HOST;
@@ -272,9 +275,9 @@
 	    return 1;
 
 	case T_IP:
-	    if (ap[i].x.ip.net != INADDR_NONE
+	    if (ap[i].x.ip.net.s_addr != INADDR_NONE
 		&& (r->connection->remote_addr.sin_addr.s_addr
-		    & ap[i].x.ip.mask) == ap[i].x.ip.net) {
+		    & ap[i].x.ip.mask.s_addr) == ap[i].x.ip.net.s_addr) {
 		return 1;
 	    }
 	    break;
