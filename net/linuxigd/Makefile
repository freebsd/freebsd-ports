# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	linuxigd
PORTVERSION=	1.0
PORTREVISION=	9
CATEGORIES=	net
MASTER_SITES=	SF/linux-igd/linux-igd/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux UPnP Internet Gateway Device

LIB_DEPENDS=	upnp.9:${PORTSDIR}/devel/upnp

USE_RC_SUBR=	linuxigd
USES=		gmake
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}

MAN8=		upnpd.8

NO_STAGE=	yes
post-extract:
	@${RM} ${WRKSRC}/iptc.?

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g"

.include <bsd.port.mk>
