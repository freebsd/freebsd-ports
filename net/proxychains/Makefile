# New ports collection makefile for:	proxychains
# Date created:		14 jui 2003
# Whom:			Patrick MARIE <mycroft@virgaria.org>
# $FreeBSD$

PORTNAME=	proxychains
PORTVERSION=	1.8.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	proxychains

MAINTAINER=	mycroft@virgaria.org
COMMENT=	Multi-proxifier

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

INSTALLS_SHLIB=	yes

post-extract:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/proxychains/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/proxychains/proxychains ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/proxychains/proxychains.conf \
		${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/proxychains/.libs/libproxychains.so.9 \
		${PREFIX}/lib

.include <bsd.port.mk>
