PORTNAME=	intel-one-mono
DISTVERSION=	1.5.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/intel/${PORTNAME}/releases/download/V${DISTVERSION}/
DISTFILES=	${PORTNAME}-otf${EXTRACT_SUFX} ${PORTNAME}-ttf${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

MAINTAINER=	dz@dolik.dev
COMMENT=	Intel One Mono font
WWW=		https://github.com/intel/intel-one-mono

LICENSE=	OFL11

USES=		fonts zip
FONTNAME=	${PORTNAME:C/-//}

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-otf/*.otf  ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-ttf/*.ttf  ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
