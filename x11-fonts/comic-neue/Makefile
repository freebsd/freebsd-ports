# $FreeBSD$

PORTNAME=	comic-neue
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://comicneue.com/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Free Comic Sans alternative

LICENSE=	CC0-1.0

USES=		fonts zip
NO_BUILD=	yes

SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
