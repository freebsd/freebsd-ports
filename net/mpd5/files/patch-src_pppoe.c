--- src/pppoe.c.orig	2016-01-06 15:42:06 UTC
+++ src/pppoe.c
@@ -71,6 +71,7 @@
 
 /* Per link private info */
 struct pppoeinfo {
+	char		iface[IFNAMSIZ];	/* PPPoE interface name */
 	char		path[MAX_PATH];		/* PPPoE node path */
 	char		hook[NG_HOOKSIZ];	/* hook on that node */
 	char		session[MAX_SESSION];	/* session name */
@@ -165,7 +166,7 @@ static int 	PppoeListen(Link l);
 static int 	PppoeUnListen(Link l);
 static void	PppoeNodeUpdate(Link l);
 static void	PppoeListenEvent(int type, void *arg);
-static int 	CreatePppoeNode(struct PppoeIf *PIf, const char *path, const char *hook);
+static int 	CreatePppoeNode(struct PppoeIf *PIf, const char *iface, const char *path, const char *hook);
 
 static void	PppoeDoClose(Link l);
 
@@ -282,6 +283,7 @@ PppoeInit(Link l)
 	pe = (PppoeInfo)(l->info = Malloc(MB_PHYS, sizeof(*pe)));
 	pe->incoming = 0;
 	pe->opened = 0;
+	snprintf(pe->iface, sizeof(pe->iface), "undefined");
 	snprintf(pe->path, sizeof(pe->path), "undefined:");
 	snprintf(pe->hook, sizeof(pe->hook), "undefined");
 	snprintf(pe->session, sizeof(pe->session), "*");
@@ -660,6 +662,16 @@ PppoeCtrlReadEvent(int type, void *arg)
 		break;
 	    }
 #endif
+#ifdef NGM_PPPOE_PADM_COOKIE
+	    case NGM_PPPOE_HURL:
+		Log(LG_PHYS, ("PPPoE: rec'd HURL \"%s\"",
+		  ((struct ngpppoe_padm *)u.resp.data)->msg));
+		break;
+	    case NGM_PPPOE_MOTM:
+		Log(LG_PHYS, ("PPPoE: rec'd MOTM \"%s\"",
+		  ((struct ngpppoe_padm *)u.resp.data)->msg));
+		break;
+#endif
 	    default:
 		Log(LG_PHYS, ("PPPoE: rec'd command %lu from \"%s\"",
 		    (u_long)u.resp.header.cmd, path));
@@ -695,6 +707,7 @@ PppoeStat(Context ctx)
 	}
 
 	Printf("PPPoE configuration:\r\n");
+	Printf("\tIface Name   : %s\r\n", pe->iface);
 	Printf("\tIface Node   : %s\r\n", pe->path);
 	Printf("\tIface Hook   : %s\r\n", pe->hook);
 	Printf("\tSession      : %s\r\n", pe->session);
@@ -748,12 +761,8 @@ static int
 PppoePeerIface(Link l, void *buf, size_t buf_len)
 {
 	PppoeInfo	const pppoe = (PppoeInfo)l->info;
-	char iface[IFNAMSIZ];
 
-	strlcpy(iface, pppoe->path, sizeof(iface));
-	if (iface[strlen(iface) - 1] == ':')
-		iface[strlen(iface) - 1] = '\0';
-	strlcpy(buf, iface, buf_len);
+	strlcpy(buf, pppoe->iface, buf_len);
 	return (0);
 }
 
@@ -880,7 +889,7 @@ PppoeGetMru(Link l, int conf)
 }
 
 static int 
-CreatePppoeNode(struct PppoeIf *PIf, const char *path, const char *hook)
+CreatePppoeNode(struct PppoeIf *PIf, const char *iface, const char *path, const char *hook)
 {
         union {
 		u_char          buf[sizeof(struct ng_mesg) + 2048];
@@ -892,11 +901,6 @@ CreatePppoeNode(struct PppoeIf *PIf, con
 	uint32_t f;
 
 	/* Make sure interface is up. */
-	char iface[IFNAMSIZ];
-
-	strlcpy(iface, path, sizeof(iface));
-	if (iface[strlen(iface) - 1] == ':')
-		iface[strlen(iface) - 1] = '\0';
 	if (ExecCmdNosh(LG_PHYS2, iface, "%s %s up", _PATH_IFCONFIG, iface) != 0) {
 		Log(LG_ERR, ("PPPoE: can't bring up interface %s",
 		    iface));
@@ -1501,7 +1505,7 @@ PppoeGetNode(Link l)
 		    l->name));
 		return;
 	}
-	if (CreatePppoeNode(&PppoeIfs[free], pi->path, pi->hook)) {
+	if (CreatePppoeNode(&PppoeIfs[free], pi->iface, pi->path, pi->hook)) {
 		strlcpy(PppoeIfs[free].ifnodepath,
 		    pi->path,
 		    sizeof(PppoeIfs[free].ifnodepath));
@@ -1673,7 +1677,7 @@ PppoeSetCommand(Context ctx, int ac, cha
 {
 	const PppoeInfo pi = (PppoeInfo) ctx->lnk->info;
 	const char *hookname = ETHER_DEFAULT_HOOK;
-	const char *colon;
+	int i;
 #ifdef NGM_PPPOE_SETMAXP_COOKIE
 	int ap;
 #endif
@@ -1684,9 +1688,17 @@ PppoeSetCommand(Context ctx, int ac, cha
 			hookname = av[1];
 			/* fall through */
 		case 1:
-			colon = (av[0][strlen(av[0]) - 1] == ':') ? "" : ":";
-			snprintf(pi->path, sizeof(pi->path),
-			    "%s%s", av[0], colon);
+			strlcpy(pi->iface, av[0], sizeof(pi->iface));
+			strlcpy(pi->path, pi->iface, sizeof(pi->path) - 1);
+			for (i = 0; i < sizeof(pi->path) - 1; i++) {
+				if (pi->path[i] == '.' || pi->path[i] == ':')
+					pi->path[i] = '_';
+				else if (pi->path[i] == '\0') {
+					pi->path[i] = ':';
+					pi->path[i + 1] = '\0';
+					break;
+				}
+			}
 			strlcpy(pi->hook, hookname, sizeof(pi->hook));
 			break;
 		default:
