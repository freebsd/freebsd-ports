# $FreeBSD$

PORTNAME=	noto
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.google.com/get/noto/pkgs/

DISTNAME=	${PORTNAME:S|n|N|}-hinted

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Google font family

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		zip
NO_BUILD=	yes

FONTDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"
WRKSRC=		${WRKDIR}

do-install:
	${MKDIR} ${STAGEDIR}${FONTDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.otf ${STAGEDIR}${FONTDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTDIR}

.include <bsd.port.mk>
