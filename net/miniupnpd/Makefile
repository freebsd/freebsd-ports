PORTNAME=	miniupnpd
DISTVERSION=	2.3.11
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.free.fr/files/ \
		https://github.com/miniupnp/miniupnp/releases/download/${PORTNAME}_${DISTVERSION:S|.|_|g}/

PATCH_SITES=	https://github.com/miniupnp/miniupnp/compare/
PATCHFILES=	miniupnpd_2_3_11...37656e7ddd5efe4786f6ae7ad007eb538535a56a.patch:-p2

PATCH_SITES+=	https://github.com/Self-Hosting-Group/miniupnp/commit/
# miniupnpd/pf: select the NAT ruleset for DIOCCHANGERULE in delete_nat_rule() (backport)
PATCHFILES+=	0f668f1fbc7900b7d6e0efcb30b35f0190f6de58.patch:-p2
# miniupnpd/pf: fix IPv6 pinhole delete (PF_CHANGE_GET_TICKET zeroed by memset) with libpfctl (backport)
PATCHFILES+=	56d313b92eeb7f5b8c2532ecf3d415f6da39ef2e.patch:-p2
# miniupnpd: UPnP IGDv2 Microsoft/Apple compatibility
PATCHFILES+=	f94e5bf7a60a41911af8d7e23cdb4ebe166257e2.patch:-p2
# miniupnpd: Improve start banner and add security warnings
PATCHFILES+=	0151834776e6a2e062ff49907835563fa1aa08d7.patch:-p2
# miniupnpd: Less excessive logging by default
PATCHFILES+=	17a4fef49534f85899dcdb87ad553c6a31ceed82.patch:-p2
# miniupnpd: Log IPv4 mapping disabled/enabled messages by default
PATCHFILES+=	5857e1937bce2b4546e0f12f27795d6af20a80d1.patch:-p2
# miniupnpd: Fix IPv4 mapping re-enable after network down/up on CGNAT
PATCHFILES+=	75ab13ce1197c3f6b993e48e291456b127e17bef.patch:-p2
# miniupnpd: No IPv4 mapping disabled logging on requests, but more cases
PATCHFILES+=	16afc35f65d8b494790157ebcf4e8505dc559b4c.patch:-p2
# miniupnpd: Clearer IPv4 mapping disabled/enabled logging
PATCHFILES+=	23a044f57bf229a1002333a18e8daa3cc1e09e30.patch:-p2
# miniupnpd: Add `default_min_port`/max options for IPv6/IPv4
PATCHFILES+=	153d03e2f01b29196b53faf96a06b1784554db25.patch:-p2
# miniupnpd: Standardise request/action logging with `LOG_INFO`
PATCHFILES+=	55c7ffc1bc53d25cdacd098d09d8c763057a042e.patch:-p2

MAINTAINER=	rcm@FreeBSD.org
COMMENT=	Lightweight UPnP IGD & PCP/NAT-PMP daemon which uses pf
WWW=		https://miniupnp.tuxfamily.org/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libpfctl.so:net/libpfctl

USES=		cpe
CPE_VENDOR=	miniupnp_project

USE_RC_SUBR=	${PORTNAME}

HAS_CONFIGURE=	yes
# unconditionally use pf, ipfw does not work on FreeBSD
CONFIGURE_ARGS=	--disable-pppconn --firewall=pf --libpfctl --vendorcfg
MAKE_ENV=	MANPREFIX=${PREFIX}/share
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	etc/miniupnpd.conf.sample \
		share/man/man8/miniupnpd.8.gz \
		sbin/miniupnpd

OPTIONS_DEFINE=		CHECK_PORTINUSE IPV6 LEASEFILE UPNP_IGDV2 UPNP_STRICT
CHECK_PORTINUSE_DESC=		Check if ports are in use
LEASEFILE_DESC=			Enable lease file
UPNP_IGDV2_DESC=		Build an IGDv2 instead of an IGDv1
UPNP_STRICT_DESC=		More strict UPnP specification compliance

CHECK_PORTINUSE_CONFIGURE_ON=	--portinuse
IPV6_CONFIGURE_ON=		--ipv6
LEASEFILE_CONFIGURE_ON=		--leasefile
UPNP_IGDV2_CONFIGURE_ON=	--igd2
UPNP_STRICT_CONFIGURE_ON=	--strict

.include <bsd.port.mk>
