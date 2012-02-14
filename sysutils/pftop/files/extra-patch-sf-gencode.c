$OpenBSD: patch-sf-gencode_c,v 1.1 2008/06/13 00:38:12 canacar Exp $
--- sf-gencode.c.orig	Tue Nov  6 23:34:18 2007
+++ sf-gencode.c	Wed Jun 11 19:50:10 2008
@@ -474,9 +474,107 @@ gen_proto(int proto)
 			(bpf_int32)proto));
 }
 
+#ifdef HAVE_PFSYNC_KEY
 static struct block *
 gen_hostop(bpf_u_int32 addr, bpf_u_int32 mask, int dir)
 {
+	struct block *b0, *b1, *b2, *bi, *bo;
+	const static int isrc_off = offsetof(pf_state_t, key[PF_SK_STACK].addr[0].v4);
+	const static int osrc_off = offsetof(pf_state_t, key[PF_SK_WIRE].addr[1].v4);
+	const static int idst_off = offsetof(pf_state_t, key[PF_SK_STACK].addr[1].v4);
+	const static int odst_off = offsetof(pf_state_t, key[PF_SK_WIRE].addr[0].v4);
+
+	const static int igwy1_off = offsetof(pf_state_t, key[PF_SK_WIRE].addr[0].v4);
+	const static int ogwy1_off = offsetof(pf_state_t, key[PF_SK_STACK].addr[1].v4);
+	const static int igwy2_off = offsetof(pf_state_t, key[PF_SK_WIRE].addr[1].v4);
+	const static int ogwy2_off = offsetof(pf_state_t, key[PF_SK_STACK].addr[0].v4);
+
+	addr = ntohl(addr);
+	mask = ntohl(mask);
+
+	bi = gen_cmp(offsetof(pf_state_t, direction), BPF_B, (bpf_int32)PF_IN);
+	bo = gen_cmp(offsetof(pf_state_t, direction), BPF_B, (bpf_int32)PF_OUT);
+
+	switch (dir) {
+
+	case Q_SRC:
+		b1 = gen_mcmp(osrc_off, BPF_W, addr, mask);
+		gen_and(bo, b1);
+		b0 = gen_mcmp(isrc_off, BPF_W, addr, mask);
+		gen_and(bi, b0);
+		gen_or(b0, b1);
+		break;
+
+	case Q_DST:
+		b1 = gen_mcmp(odst_off, BPF_W, addr, mask);
+		gen_and(bo, b1);
+		b0 = gen_mcmp(idst_off, BPF_W, addr, mask);
+		gen_and(bi, b0);
+		gen_or(b0, b1);
+		break;
+
+	case Q_GATEWAY:
+		/* (in && (addr == igwy1 || addr == igwy2)) ||
+		   (out && (addr == ogwy1 || addr == ogwy2))  phew! */
+		b1 = gen_mcmp(igwy1_off, BPF_W, addr, mask);
+		b0 = gen_mcmp(igwy2_off, BPF_W, addr, mask);
+		gen_or(b0, b1);
+		gen_and(bi, b1);
+		b2 = gen_mcmp(ogwy1_off, BPF_W, addr, mask);
+		b0 = gen_mcmp(ogwy2_off, BPF_W, addr, mask);
+		gen_or(b2, b0);
+		gen_and(bo, b0);
+		gen_or(b0, b1);
+		break;
+
+	case Q_AND:
+		b1 = gen_mcmp(isrc_off, BPF_W, addr, mask);
+		b0 = gen_mcmp(idst_off, BPF_W, addr, mask);
+		gen_and(b0, b1);
+		gen_and(bi, b1);
+		b2 = gen_mcmp(osrc_off, BPF_W, addr, mask);
+		b0 = gen_mcmp(odst_off, BPF_W, addr, mask);
+		gen_and(b2, b0);
+		gen_and(bo, b0);
+		gen_or(b0, b1);
+		break;
+
+	case Q_OR:
+		b1 = gen_mcmp(isrc_off, BPF_W, addr, mask);
+		b0 = gen_mcmp(idst_off, BPF_W, addr, mask);
+		gen_or(b0, b1);
+		gen_and(bi, b1);
+		b2 = gen_mcmp(osrc_off, BPF_W, addr, mask);
+		b0 = gen_mcmp(odst_off, BPF_W, addr, mask);
+		gen_or(b2, b0);
+		gen_and(bo, b0);
+		gen_or(b0, b1);
+		break;
+
+	case Q_DEFAULT:
+		b1 = gen_mcmp(isrc_off, BPF_W, addr, mask);
+		b0 = gen_mcmp(idst_off, BPF_W, addr, mask);
+		gen_or(b0, b1);
+		b0 = gen_mcmp(osrc_off, BPF_W, addr, mask);
+		gen_or(b0, b1);
+		b0 = gen_mcmp(odst_off, BPF_W, addr, mask);
+		gen_or(b0, b1);
+		break;
+
+	default:
+		sf_error("Internal error: Invalid direcion specifier: %d", dir);
+	}
+
+	b0 = gen_linktype(ETHERTYPE_IP);
+	gen_and(b0, b1);
+
+	return b1;
+}
+
+#else
+static struct block *
+gen_hostop(bpf_u_int32 addr, bpf_u_int32 mask, int dir)
+{
 	struct block *b0, *b1, *b2;
 	const static int lan_off = offsetof(pf_state_t, lan.addr.v4);
 	const static int gwy_off = offsetof(pf_state_t, gwy.addr.v4);
@@ -542,6 +640,7 @@ gen_hostop(bpf_u_int32 addr, bpf_u_int32 mask, int dir
 
 	return b1;
 }
+#endif
 
 static struct block *
 gen_hostcmp6(u_int off, u_int32_t *a, u_int32_t *m)
@@ -560,9 +659,108 @@ gen_hostcmp6(u_int off, u_int32_t *a, u_int32_t *m)
 	return b1;
 }
 
+#ifdef HAVE_PFSYNC_KEY
 static struct block *
 gen_hostop6(struct in6_addr *addr, struct in6_addr *mask, int dir)
+
 {
+	struct block *b0, *b1, *b2, *bi, *bo;
+	u_int32_t *a, *m;
+	const static int isrc_off = offsetof(pf_state_t, key[PF_SK_STACK].addr[0].v6);
+	const static int osrc_off = offsetof(pf_state_t, key[PF_SK_WIRE].addr[1].v6);
+	const static int idst_off = offsetof(pf_state_t, key[PF_SK_STACK].addr[1].v6);
+	const static int odst_off = offsetof(pf_state_t, key[PF_SK_WIRE].addr[0].v6);
+
+	const static int igwy1_off = offsetof(pf_state_t, key[PF_SK_WIRE].addr[0].v6);
+	const static int ogwy1_off = offsetof(pf_state_t, key[PF_SK_STACK].addr[1].v6);
+	const static int igwy2_off = offsetof(pf_state_t, key[PF_SK_WIRE].addr[1].v6);
+	const static int ogwy2_off = offsetof(pf_state_t, key[PF_SK_STACK].addr[0].v6);
+
+	a = (u_int32_t *)addr;
+	m = (u_int32_t *)mask;
+
+	bi = gen_cmp(offsetof(pf_state_t, direction), BPF_B, (bpf_int32)PF_IN);
+	bo = gen_cmp(offsetof(pf_state_t, direction), BPF_B, (bpf_int32)PF_OUT);
+
+	switch (dir) {
+
+	case Q_SRC:
+		b1 = gen_hostcmp6(osrc_off, a, m);
+		gen_and(bo, b1);
+		b0 = gen_hostcmp6(isrc_off, a, m);
+		gen_and(bi, b0);
+		gen_or(b0, b1);
+		break;
+
+	case Q_DST:
+		b1 = gen_hostcmp6(odst_off, a, m);
+		gen_and(bo, b1);
+		b0 = gen_hostcmp6(idst_off, a, m);
+		gen_and(bi, b0);
+		gen_or(b0, b1);
+		break;
+
+	case Q_GATEWAY:
+		/* (in && (addr == igwy1 || addr == igwy2)) ||
+		   (out && (addr == ogwy1 || addr == ogwy2))  phew! */
+		b1 = gen_hostcmp6(igwy1_off, a, m);
+		b0 = gen_hostcmp6(igwy2_off, a, m);
+		gen_or(b0, b1);
+		gen_and(bi, b1);
+		b2 = gen_hostcmp6(ogwy1_off, a, m);
+		b0 = gen_hostcmp6(ogwy2_off, a, m);
+		gen_or(b2, b0);
+		gen_and(bo, b0);
+		gen_or(b0, b1);
+		break;
+
+	case Q_AND:
+		b1 = gen_hostcmp6(isrc_off, a, m);
+		b0 = gen_hostcmp6(idst_off, a, m);
+		gen_and(b0, b1);
+		gen_and(bi, b1);
+		b2 = gen_hostcmp6(osrc_off, a, m);
+		b0 = gen_hostcmp6(odst_off, a, m);
+		gen_and(b2, b0);
+		gen_and(bo, b0);
+		gen_or(b0, b1);
+		break;
+
+	case Q_OR:
+		b1 = gen_hostcmp6(isrc_off, a, m);
+		b0 = gen_hostcmp6(idst_off, a, m);
+		gen_or(b0, b1);
+		gen_and(bi, b1);
+		b2 = gen_hostcmp6(osrc_off, a, m);
+		b0 = gen_hostcmp6(odst_off, a, m);
+		gen_or(b2, b0);
+		gen_and(bo, b0);
+		gen_or(b0, b1);
+		break;
+
+	case Q_DEFAULT:
+		b1 = gen_hostcmp6(isrc_off, a, m);
+		b0 = gen_hostcmp6(idst_off, a, m);
+		gen_or(b0, b1);
+		b0 = gen_hostcmp6(osrc_off, a, m);
+		gen_or(b0, b1);
+		b0 = gen_hostcmp6(odst_off, a, m);
+		gen_or(b0, b1);
+		break;
+
+	default:
+		sf_error("Internal error: Invalid direcion specifier: %d", dir);
+	}
+
+	b0 = gen_linktype(ETHERTYPE_IPV6);
+	gen_and(b0, b1);
+
+	return b1;
+}
+#else
+static struct block *
+gen_hostop6(struct in6_addr *addr, struct in6_addr *mask, int dir)
+{
 	struct block *b0, *b1, *b2;
 	u_int32_t *a, *m;
 
@@ -630,6 +828,7 @@ gen_hostop6(struct in6_addr *addr, struct in6_addr *ma
 	gen_and(b0, b1);
 	return b1;
 }
+#endif
 
 static const char *
 get_modifier_by_id(int id)
@@ -748,9 +947,107 @@ gen_proto_abbrev(proto)
 	return b1;
 }
 
+#ifdef HAVE_PFSYNC_KEY
 struct block *
 gen_portop(int port, int proto, int dir)
 {
+	struct block *b0, *b1, *b2, *bi, *bo;
+	const static int isrc_off = offsetof(pf_state_t, key[PF_SK_STACK].port[0]);
+	const static int osrc_off = offsetof(pf_state_t, key[PF_SK_WIRE].port[1]);
+	const static int idst_off = offsetof(pf_state_t, key[PF_SK_STACK].port[1]);
+	const static int odst_off = offsetof(pf_state_t, key[PF_SK_WIRE].port[0]);
+
+	const static int igwy1_off = offsetof(pf_state_t, key[PF_SK_WIRE].port[0]);
+	const static int ogwy1_off = offsetof(pf_state_t, key[PF_SK_STACK].port[1]);
+	const static int igwy2_off = offsetof(pf_state_t, key[PF_SK_WIRE].port[1]);
+	const static int ogwy2_off = offsetof(pf_state_t, key[PF_SK_STACK].port[0]);
+
+	port = ntohs(port);
+
+	bi = gen_cmp(offsetof(pf_state_t, direction), BPF_B, (bpf_int32)PF_IN);
+	bo = gen_cmp(offsetof(pf_state_t, direction), BPF_B, (bpf_int32)PF_OUT);
+
+	switch (dir) {
+
+	case Q_SRC:
+		b1 = gen_cmp(osrc_off, BPF_H, (bpf_int32)port);
+		gen_and(bo, b1);
+		b0 = gen_cmp(isrc_off, BPF_H, (bpf_int32)port);
+		gen_and(bi, b0);
+		gen_or(b0, b1);
+		break;
+
+	case Q_DST:
+		b1 = gen_cmp(odst_off, BPF_H, (bpf_int32)port);
+		gen_and(bo, b1);
+		b0 = gen_cmp(idst_off, BPF_H, (bpf_int32)port);
+		gen_and(bi, b0);
+		gen_or(b0, b1);
+		break;
+
+	case Q_GATEWAY:
+		/* (in && (addr == igwy1 || addr == igwy2)) ||
+		   (out && (addr == ogwy1 || addr == ogwy2))  phew! */
+		b1 = gen_cmp(igwy1_off, BPF_H, (bpf_int32)port);
+		b0 = gen_cmp(igwy2_off, BPF_H, (bpf_int32)port);
+		gen_or(b0, b1);
+		gen_and(bi, b1);
+		b2 = gen_cmp(ogwy1_off, BPF_H, (bpf_int32)port);
+		b0 = gen_cmp(ogwy2_off, BPF_H, (bpf_int32)port);
+		gen_or(b2, b0);
+		gen_and(bo, b0);
+		gen_or(b0, b1);
+		break;
+
+	case Q_AND:
+		b1 = gen_cmp(isrc_off, BPF_H, (bpf_int32)port);
+		b0 = gen_cmp(idst_off, BPF_H, (bpf_int32)port);
+		gen_and(b0, b1);
+		gen_and(bi, b1);
+		b2 = gen_cmp(osrc_off, BPF_H, (bpf_int32)port);
+		b0 = gen_cmp(odst_off, BPF_H, (bpf_int32)port);
+		gen_and(b2, b0);
+		gen_and(bo, b0);
+		gen_or(b0, b1);
+		break;
+
+	case Q_OR:
+		b1 = gen_cmp(isrc_off, BPF_H, (bpf_int32)port);
+		b0 = gen_cmp(idst_off, BPF_H, (bpf_int32)port);
+		gen_or(b0, b1);
+		gen_and(bi, b1);
+		b2 = gen_cmp(osrc_off, BPF_H, (bpf_int32)port);
+		b0 = gen_cmp(odst_off, BPF_H, (bpf_int32)port);
+		gen_or(b2, b0);
+		gen_and(bo, b0);
+		gen_or(b0, b1);
+		break;
+
+	case Q_DEFAULT:
+		b1 = gen_cmp(isrc_off, BPF_H, (bpf_int32)port);
+		b0 = gen_cmp(idst_off, BPF_H, (bpf_int32)port);
+		gen_or(b0, b1);
+		b0 = gen_cmp(osrc_off, BPF_H, (bpf_int32)port);
+		gen_or(b0, b1);
+		b0 = gen_cmp(odst_off, BPF_H, (bpf_int32)port);
+		gen_or(b0, b1);
+		break;
+
+	default:
+		sf_error("Internal error: Invalid direcion specifier: %d", dir);
+	}
+
+
+
+	b0 = gen_proto(proto);
+	gen_and(b0, b1);
+
+	return b1;
+}
+#else
+struct block *
+gen_portop(int port, int proto, int dir)
+{
 	struct block *b0, *b1, *b2;
 	const static int lan_off = offsetof(pf_state_t, lan.port);
 	const static int gwy_off = offsetof(pf_state_t, gwy.port);
@@ -815,6 +1112,7 @@ gen_portop(int port, int proto, int dir)
 
 	return b1;
 }
+#endif
 
 static struct block *
 gen_port(int port, int ip_proto, int dir)
