PORTNAME=	cozette
DISTVERSIONPREFIX=	v.
DISTVERSION=	1.19.2
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/slavfox/Cozette/releases/download/${DISTVERSIONFULL}/
DISTNAME=	${FONTNAME}Fonts
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

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.otb ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
