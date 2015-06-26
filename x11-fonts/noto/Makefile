# $FreeBSD$

PORTNAME=	noto
PORTVERSION=	1.0.4
CATEGORIES=	x11-fonts
MASTER_SITES=	https://noto-website.storage.googleapis.com/pkgs/

DISTNAME=	${PORTNAME:S|n|N|}-hinted

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Google font family

LICENSE=	APACHE20 OFL11
LICENSE_COMB=	multi

USES=		fonts zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
