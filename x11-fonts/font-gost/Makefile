# New ports collection makefile for:	font-gost
# Date created:		2010-01-15
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	gost
PORTVERSION=	0.1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://sd.ascon.ru/ftp/Public/Utils/DWG-DXF/ \
		http://fbsd.zlonet.ru/distfiles/
PKGNAMEPREFIX=	font-
DISTNAME=	TTF_FON

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	GOST TrueType fonts

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_ZIP=	yes
NO_BUILD=	yes
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
FONTSDIR=	${PREFIX}/lib/X11/fonts/gost

WRKSRC=		${WRKDIR}/Fonts

do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.TTF ${FONTSDIR}

post-install:
	${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}
	${ECHO_MSG}
	${CAT} ${PKGMESSAGE}
	${ECHO_MSG}
	@${ECHO_MSG} "Standart GOST font. GOST 2.304-81"
	@${ECHO_MSG} "Pay attention to copyright issues before\
		any commercial use this fonts."
	@${ECHO_MSG} "Copyright (c) 1996-2010. ASCON. All Rights Reserved."

.include <bsd.port.mk>
