# Created by: Thierry Thomas <thierry@pompo.net>

PORTNAME=	stixfonts
PORTVERSION=	2.13
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-fonts

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	OpenType Unicode fonts for Scientific, Technical, and Math texts

LICENSE=	OFL11

USES=		fonts xorg
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	stipub

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

FONTNAME=	STIX

OPTIONS_DEFINE=	DOCS

PORTDOCS=	STIX-Two_glyph_sets.xlsx STIXTwoMath-Regular.pdf	\
		STIXTwoText-Regular.pdf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} &&	\
	${FIND} fonts -type file -exec ${INSTALL_DATA} {} ${STAGEDIR}${FONTSDIR} \;
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
