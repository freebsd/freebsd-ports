PORTNAME=	intel-one-mono
DISTVERSION=	1.4.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/intel/${PORTNAME}/releases/download/V${DISTVERSION}/
DISTFILES=	otf${EXTRACT_SUFX} ttf${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

MAINTAINER=	dz@dolik.dev
COMMENT=	Intel One Mono font

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/ttf/OFL.txt

USES=		fonts zip
FONTNAME=	${PORTNAME:C/-//}

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/otf/*.otf  ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf  ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
