# $FreeBSD$

PORTNAME=	alef
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://alef.hagilda.com/
DISTNAME=	Alef

MAINTAINER=	cpm@fbsd.es
COMMENT=	Free multi-lingual font designed for screens

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL-license.txt

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USES=		zip
USE_XORG=	x11

NO_WRKSUBDIR=	yes
FONTSDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}

PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"

PORTDOCS=	COMING-SOON.txt readme.txt

MKFONTSCL_CMD=	${LOCALBASE}/bin/mkfontscale
MKFONTDIR_CMD=	${LOCALBASE}/bin/mkfontdir

OPTIONS_DEFINE=	DOCS

post-extract:
	${MV} ${WRKSRC}/--COMING-SOON--.txt ${WRKSRC}/COMING-SOON.txt

do-build:
	${MKFONTSCL_CMD} ${WRKSRC}/TTF
	${MKFONTDIR_CMD} ${WRKSRC}/TTF

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/TTF/* ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
