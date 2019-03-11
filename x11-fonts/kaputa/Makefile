# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kaputa
PORTVERSION=	1.000
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.kaputa.com/slword/
DISTNAME=	${PORTNAME}unicode
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Unicode font for Sinhala script

USES=		fonts zip
NO_BUILD=	yes
PLIST_FILES=	${FONTSDIR}/kaputa.ttf

post-extract:
	@${MKDIR} ${WRKSRC}/
	@${MV} ${WRKDIR}/kaputaunicode.ttf ${WRKSRC}/kaputa.ttf

do-install:
	@${INSTALL} -d ${STAGEDIR}${FONTSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
