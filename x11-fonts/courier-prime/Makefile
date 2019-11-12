# $FreeBSD$

PORTNAME=	courier-prime
PORTVERSION=	g20180831
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://quoteunquoteapps.com/courierprime/downloads/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	flo@snakeoilproductions.net
COMMENT=	It\'s Courier, just better

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/"Courier Prime/LICENSE/OFL.txt"

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/"Courier Prime"/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
