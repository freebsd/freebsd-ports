# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sourceserifpro
PORTVERSION=	3.001
DISTVERSIONSUFFIX=	R
CATEGORIES=	x11-fonts
PKGNAMESUFFIX=	-ttf

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of fonts by Adobe designed for UI

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE.md

PORTSCOUT=	skipv:variable-fonts

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

FONTNAME=	SourceSerifPro
SUB_FILES=	pkg-message

GH_ACCOUNT=	adobe-fonts
GH_PROJECT=	source-serif-pro
USE_GITHUB=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/TTF/*.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
