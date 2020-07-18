# $FreeBSD$

PORTNAME=	comic-neue
PORTVERSION=	2.5
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-fonts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Comic Sans alternative

LICENSE=	OFL11
LICENSE_FILE=	${WRKDIR}/comicneue-${PORTVERSION}/OFL.txt

USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	crozynski
GH_PROJECT=	comicneue

NO_BUILD=	yes
WRKSRC_SUBDIR=		Fonts/OTF

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/ComicNeue-Angular/*.otf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/ComicNeue/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
