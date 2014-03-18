# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	pingwi
PORTVERSION=	0.1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.pingwinsoft.ru/system/uploads/16/original/ \
		http://fbsd.zlonet.ru/distfiles/
PKGNAMEPREFIX=	font-
DISTNAME=	fonts_test

MAINTAINER=	vg@FreeBSD.org
COMMENT=	PingWi Typography fonts

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USES=		zip
NO_BUILD=	yes
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
FONTSDIR=	${PREFIX}/lib/X11/fonts/pingwi
SUB_FILES=	pkg-message
SUB_LIST=	FONTSDIR=${FONTSDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
