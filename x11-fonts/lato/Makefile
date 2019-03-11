# $FreeBSD$

PORTNAME=	lato
PORTVERSION=	g20180831
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.latofonts.com/download/
DISTNAME=	Lato2OFL
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	flo@snakeoilproductions.net
COMMENT=	Sans-serif type family

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/Lato2OFL/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Lato2OFL/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
