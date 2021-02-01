# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	sourcesanspro
PORTVERSION=	3.028
MASTER_SITES=	https://github.com/adobe-fonts/source-sans-pro/releases/download/${PORTVERSION}R/
CATEGORIES=	x11-fonts
PKGNAMESUFFIX=	-ttf
DISTNAME=	source-sans-${PORTVERSION:R}v${PORTVERSION:E}R

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of fonts by Adobe designed for user interfaces

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTNAME=	SourceSansPro
SUB_FILES=	pkg-message

PORTSCOUT=	skipv:variable-fonts

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/TTF/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
