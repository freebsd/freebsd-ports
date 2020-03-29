# Created by: Mateusz Piotrowski <0mp@FreeBSD.org>
# $FreeBSD$

PORTNAME=	manrope
PORTVERSION=	4.5
CATEGORIES=	x11-fonts

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Modern geometric sans-serif font

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts
FONTNAME=	Manrope
USE_GITHUB=	yes
GH_ACCOUNT=	sharanda
# Upstream does not tag releases.
GH_TAGNAME=	ec910ca75197359c1443e8e3a000cf99d76cb6d7

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/ttf/* ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/otf/* ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/web/* ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/variable/* ${STAGEDIR}${FONTSDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
