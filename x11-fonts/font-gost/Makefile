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

NO_STAGE=	yes
do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.TTF ${FONTSDIR}

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
