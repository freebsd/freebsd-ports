PORTNAME=	miniupnpd
DISTVERSION=	2.3.9
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.free.fr/files/ \
		https://github.com/miniupnp/miniupnp/releases/download/${PORTNAME}_${DISTVERSION:S|.|_|g}/

PATCH_SITES=	https://github.com/miniupnp/miniupnp/commit/
PATCHFILES=	7949a7acb3b8471681157863387339ea2ca749fb.patch:-p2

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
CONFIGURE_ARGS=	--firewall=pf \
		--libpfctl \
		--vendorcfg
MAKE_ENV=	MANPREFIX=${PREFIX}/share
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	etc/miniupnpd.conf.sample \
		sbin/miniupnpd \
		share/man/man8/miniupnpd.8.gz

OPTIONS_DEFINE=		CHECK_PORTINUSE IPV6 LEASEFILE UPNP_IGDV2 UPNP_NOPPP \
			UPNP_STRICT
CHECK_PORTINUSE_DESC=	Check if ports are in use
LEASEFILE_DESC=		Enable lease file
UPNP_IGDV2_DESC=	Build support for UPnP IGDv2 and IPv6 with IGD into the daemon
UPNP_NOPPP_DESC=	No old/IGDv1-only extra WANPPPConnection SSDP announcements workaround
UPNP_STRICT_DESC=	More strict UPnP specification compliance

CHECK_PORTINUSE_CONFIGURE_ON=	--portinuse
IPV6_CONFIGURE_ON=		--ipv6
LEASEFILE_CONFIGURE_ON=		--leasefile
UPNP_IGDV2_CONFIGURE_ON=	--igd2
UPNP_NOPPP_CONFIGURE_ON=	--disable-pppconn
UPNP_STRICT_CONFIGURE_ON=	--strict

.include <bsd.port.mk>
