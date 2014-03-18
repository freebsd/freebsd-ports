# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	gost
PORTVERSION=	0.2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://sd.ascon.ru/ftp/Public/Utils/DWG-DXF/ \
		LOCAL/vg
PKGNAMEPREFIX=	font-
DISTNAME=	TTF_FON

MAINTAINER=	vg@FreeBSD.org
COMMENT=	GOST TrueType fonts

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USES=		zip
NO_BUILD=	yes
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
FONTSDIR=	${PREFIX}/lib/X11/fonts/gost
SUB_FILES=	pkg-message
SUB_LIST=	FONTSDIR=${FONTSDIR}
WRKSRC=		${WRKDIR}/Fonts

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.TTF ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
