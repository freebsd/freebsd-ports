PORTNAME=	cozette
DISTVERSIONPREFIX=	v.
DISTVERSION=	1.23.1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/slavfox/Cozette/releases/download/${DISTVERSIONFULL}/
DISTNAME=	${FONTNAME}Fonts-v-${DISTVERSION:S/./-/g}
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	laxul@pm.me
COMMENT=	Bitmap programming font optimized for coziness
WWW=		https://github.com/slavfox/Cozette

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fonts zip
FONTNAME=	Cozette

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${FONTNAME}Fonts

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.otb ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
