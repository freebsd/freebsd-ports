# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	sourcesanspro-ttf
PORTVERSION=	1.075
CATEGORIES=	x11-fonts

MAINTAINER=	office@FreeBSD.org
COMMENT=	Set of fonts by Adobe designed for user interfaces

LICENSE=	OFL11

USE_GITHUB=	yes
GH_ACCOUNT=	adobe-fonts
GH_PROJECT=	source-sans-pro
GH_TAGNAME=	2.020R-ro/${PORTVERSION}R-it

NO_ARCH=	yes
NO_BUILD=	yes
USES=		fonts
USE_XORG=	x11

FONTNAME=	SourceSansPro
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/TTF/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
