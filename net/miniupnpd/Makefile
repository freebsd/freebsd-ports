PORTNAME=	miniupnpd
DISTVERSION=	2.3.3
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	squat@squat.no
COMMENT=	UPnP IGD implementation which uses pf
WWW=		http://miniupnp.free.fr/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=   libpfctl.so:net/libpfctl

USES=		cpe ssl localbase:ldflags
CPE_VENDOR=	miniupnp_project

USE_GITHUB=	yes
GH_ACCOUNT=	miniupnp
GH_PROJECT=	miniupnp
GH_TAGNAME=	e439318

USE_RC_SUBR=	miniupnpd

HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB} -lpfctl

WRKSRC_SUBDIR=	miniupnpd

PLIST_FILES=	etc/miniupnpd.conf.sample \
		man/man8/miniupnpd.8.gz \
		sbin/miniupnpd

# unconditionally use pf, ipfw does not work on FreeBSD
CONFIGURE_ARGS=	--firewall=pf

OPTIONS_DEFINE=			CHECK_PORTINUSE IPV6 LEASEFILE UPNP_IGDV2 \
				UPNP_STRICT
CHECK_PORTINUSE_DESC=		Check if ports are in use
LEASEFILE_DESC=			Enable lease file
UPNP_IGDV2_DESC=		Build an IGDv2 instead of an IGDv1
UPNP_STRICT_DESC=		More strict UPnP specification compliance

CHECK_PORTINUSE_CONFIGURE_ON=	--portinuse
IPV6_CONFIGURE_ON=		--ipv6
LEASEFILE_CONFIGURE_ON=		--leasefile
UPNP_IGDV2_CONFIGURE_ON=	--igd2
UPNP_STRICT_CONFIGURE_ON=	--strict

post-patch:
	@${REINPLACE_CMD} -e 's|\(-lssl -lcrypto\)|$$(LDFLAGS) \1|g' \
	${WRKSRC}/Makefile.bsd

.include <bsd.port.mk>
