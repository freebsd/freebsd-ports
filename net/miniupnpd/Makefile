PORTNAME=	miniupnpd
DISTVERSION=	2.3.11
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	https://miniupnp.tuxfamily.org/files/ \
		https://github.com/miniupnp/miniupnp/releases/download/${PORTNAME}_${DISTVERSION:S|.|_|g}/

PATCH_SITES=	https://github.com/Self-Hosting-Group/miniupnp/commit/
# miniupnpd/pf: set pool address family
PATCHFILES=	d9ffcddba15d190e40fc68783dfedbbb61e764d0.patch:-p2
# miniupnpd: UPnP IGDv2 Microsoft/Apple compatibility
PATCHFILES+=	f94e5bf7a60a41911af8d7e23cdb4ebe166257e2.patch:-p2
# miniupnpd: Improve start banner and add security warnings
PATCHFILES+=	266d2bd9710af90c5a6f0cccc4669c1413443337.patch:-p2
# miniupnpd: Less excessive logging by default
PATCHFILES+=	a7cebfc522306295cc1745c637f64d0e7d659795.patch:-p2
# miniupnpd: Fix IPv4 mapping re-enable after if down/up on CGNAT
PATCHFILES+=	55da2ba01924b4661038ae21c4e63e751e59a7e9.patch:-p2
# miniupnpd: No IPv4 mapping disabled logging on requests, but more cases
PATCHFILES+=	c8ad7519a19e43ab7dd352fca3abe8bc6c75dbfd.patch:-p2

MAINTAINER=	squat@squat.no
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
