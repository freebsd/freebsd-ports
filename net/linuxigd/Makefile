# New ports collection makefile for:	linuxigd
# Date created:				02 August 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	linuxigd
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF/linux-igd/linux-igd/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux UPnP Internet Gateway Device

LIB_DEPENDS=	upnp.4:${PORTSDIR}/devel/upnp

BROKEN=		does not compile

USE_RC_SUBR=	linuxigd
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}

MAN8=		upnpd.8

post-extract:
	@${RM} ${WRKSRC}/iptc.?

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g"

.include <bsd.port.mk>
