# $FreeBSD$

PORTNAME=	noto
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.google.com/get/noto/pkgs/

DISTNAME=	${PORTNAME:S|n|N|}-hinted

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Google font family

LICENSE=	APACHE20

USES=		fonts zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
