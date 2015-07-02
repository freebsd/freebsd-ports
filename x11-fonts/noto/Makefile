# $FreeBSD$

PORTNAME=	noto
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://noto-website.storage.googleapis.com/pkgs/ \
		https://github.com/googlei18n/noto-emoji/raw/master/:emoji
DISTNAME=	${PORTNAME:S|n|N|}-hinted
DISTFILES=	${DISTNAME}.zip NotoEmoji-Regular.ttf:emoji
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Google font family

LICENSE=	APACHE20 OFL11
LICENSE_COMB=	multi

USES=		fonts zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

post-extract:
	${CP} ${DISTDIR}/NotoEmoji-Regular.ttf ${WRKDIR}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
