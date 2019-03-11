# $FreeBSD$

PORTNAME=	alef
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://alef.hagilda.com/
DISTNAME=	Alef

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free multi-lingual font designed for screens

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL-license.txt

USES=		fonts zip
USE_XORG=	x11

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
FONTSDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_FILES=	${FONTSDIR}/Alef-Bold.ttf \
		${FONTSDIR}/Alef-Regular.ttf

PORTDOCS=	COMING-SOON.txt readme.txt

OPTIONS_DEFINE=	DOCS

post-extract:
	${MV} ${WRKSRC}/--COMING-SOON--.txt ${WRKSRC}/COMING-SOON.txt

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/TTF/* ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
