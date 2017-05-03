# $FreeBSD$

PORTNAME=	noto
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://noto-website.storage.googleapis.com/pkgs/
DISTNAME=	${PORTNAME:S|n|N|}-hinted
DISTFILES=	${DISTNAME}.zip \
		${PORTNAME:S|n|N|}SerifCJKjp-hinted.zip \
		${PORTNAME:S|n|N|}SerifCJKkr-hinted.zip \
		${PORTNAME:S|n|N|}SerifCJKsc-hinted.zip \
		${PORTNAME:S|n|N|}SerifCJKtc-hinted.zip

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Google font family

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE_OFL.txt

USES=		fonts zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
