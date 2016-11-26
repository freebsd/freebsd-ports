# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	sourcesanspro-ttf
PORTVERSION=	2.020
DISTVERSIONSUFFIX=	R-ro/1.075R-it
CATEGORIES=	x11-fonts

MAINTAINER=	office@FreeBSD.org
COMMENT=	Set of fonts by Adobe designed for user interfaces

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	adobe-fonts
GH_PROJECT=	source-sans-pro

NO_ARCH=	yes
NO_BUILD=	yes
USES=		fonts

FONTNAME=	SourceSansPro
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/TTF/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
