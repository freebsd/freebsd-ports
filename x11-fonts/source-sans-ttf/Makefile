PORTNAME=	source-sans
PORTVERSION=	3.052
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/adobe-fonts/source-sans/releases/download/${PORTVERSION}R/
PKGNAMESUFFIX=	-ttf
DISTNAME=	TTF-source-sans-${PORTVERSION}R

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of fonts by Adobe designed for user interfaces
WWW=		https://github.com/adobe-fonts/source-sans

LICENSE=	OFL11

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTNAME=	SourceSans
SUB_FILES=	pkg-message

PORTSCOUT=	skipv:variable-fonts

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/TTF/*.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
