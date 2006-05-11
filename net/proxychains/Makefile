# New ports collection makefile for:	proxychains
# Date created:		14 jui 2003
# Whom:			Patrick MARIE <mycroft@virgaria.org>
# $FreeBSD$

PORTNAME=	proxychains
PORTVERSION=	2.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	proxychains

MAINTAINER=	mycroft@virgaria.org
COMMENT=	Multi-proxifier

USE_AUTOTOOLS=	automake:14 autoconf:213

INSTALLS_SHLIB=	yes

post-extract:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/proxychains/Makefile.in

pre-build:
	${RM} ${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/proxychains/proxychains ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/proxychains/proxychains.conf \
		${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/proxychains/.libs/libproxychains.so.2 \
		${PREFIX}/lib

.include <bsd.port.mk>
