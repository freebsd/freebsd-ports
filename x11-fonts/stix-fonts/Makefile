# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	stixfonts
PORTVERSION=	2.0.2
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

FONTNAME=	stix

OPTIONS_DEFINE=	DOCS

PORTDOCS=	STIX_${PORTVERSION}_release_notes.txt

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} OTF/* WOFF/* ${STAGEDIR}${FONTSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
