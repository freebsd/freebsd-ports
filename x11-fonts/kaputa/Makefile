# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kaputa
PORTVERSION=	1.000
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.kaputa.com/slword/
DISTNAME=	${PORTNAME}unicode
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Unicode font for Sinhala script

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale	\
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir	\
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USES=		zip
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}
NO_BUILD=	yes

post-extract:
	@${MKDIR} ${WRKSRC}/
	@${MV} ${WRKDIR}/kaputaunicode.ttf ${WRKSRC}/kaputa.ttf

do-build:
	@cd ${WRKSRC}/ && ${MKFONTSCL_CMD} && ${MKFONTDIR_CMD}

do-install:
	@${INSTALL} -d ${STAGEDIR}${FONTSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
