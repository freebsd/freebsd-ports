# $FreeBSD$

PORTNAME=	alef
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://alef.hagilda.com/
DISTNAME=	Alef

MAINTAINER=	cpm@fbsd.es
COMMENT=	A free multi-lingual font designed for screens

LICENSE=	OFL11

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USES=		zip
USE_XORG=	x11
FONTSDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes

PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"

PORTDOCS=	--COMING-SOON--.txt OFL-license.txt readme.txt

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MKDIR} ${WRKSRC}
	cd ${WRKDIR} ; ${MV} TTF ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/TTF/* ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
