# $FreeBSD$

PORTNAME=	comic-neue
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://comicneue.com/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Free Comic Sans alternative

LICENSE=	CC0
LICENSE_NAME=	CC0 1.0 Universal
LICENSE_TEXT=	See http://creativecommons.org/publicdomain/zero/1.0/
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts zip
NO_BUILD=	yes

FONTSDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
