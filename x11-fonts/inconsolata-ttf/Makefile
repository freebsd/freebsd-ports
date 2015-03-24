# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	inconsolata-ttf
PORTVERSION=	20090215
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.levien.com/type/myfonts/
DISTNAME=	Inconsolata
EXTRACT_SUFX=	.otf
EXTRACT_ONLY=

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Monospaced truetype font

USES=		fonts
FONTNAME=	inconsolata
USE_XORG=	x11
PLIST_FILES=	${FONTSDIR}/${DISTNAME}${EXTRACT_SUFX}
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
