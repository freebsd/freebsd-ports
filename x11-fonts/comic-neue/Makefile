# $FreeBSD$

PORTNAME=	comic-neue
PORTVERSION=	2.3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://comicneue.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Comic Sans alternative

LICENSE=	CC0-1.0

USES=		fonts zip
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/OTF

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
