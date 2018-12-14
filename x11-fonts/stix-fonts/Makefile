# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	stixfonts
PORTVERSION=	2.0.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/stipub/stixfonts/archive/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	OpenType Unicode fonts for Scientific, Technical, and Math texts

LICENSE=	OFL11

USES=		fonts zip
USE_XORG=	x11

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

FONTNAME=	stix

OPTIONS_DEFINE=	DOCS

PORTDOCS=	STIX_${PORTVERSION}_release_notes.txt STIX_${PORTVERSION}_stylistic_sets.pdf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} OTF/* WOFF/* ${STAGEDIR}${FONTSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
