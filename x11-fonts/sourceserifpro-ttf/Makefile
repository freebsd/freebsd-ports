PORTNAME=	sourceserifpro
PORTVERSION=	3.001
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/adobe-fonts/source-serif-pro/releases/download/${PORTVERSION}R/
PKGNAMESUFFIX=	-ttf
DISTNAME=	source-serif-pro-${PORTVERSION}R

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of fonts by Adobe designed for UI

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes

FONTNAME=	SourceSerifPro
SUB_FILES=	pkg-message

PORTSCOUT=	skipv:variable-fonts

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/TTF/*.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
