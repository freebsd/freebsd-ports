# $FreeBSD$

PORTNAME=	cosmic-sans-neue-mono
PORTVERSION=	1.3.1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://openfontlibrary.org/assets/downloads/${PORTNAME}/feb9d273fd3f3068493fd183c589ecff/
DISTNAME=	${PORTNAME}

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Programming font, designed with functionality in mind

LICENSE=	OFL11

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

FONTDIR=	${STAGEDIR}${PREFIX}/lib/X11/fonts/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${FONTDIR}
	cd ${WRKSRC}/OTF && \
		${INSTALL_DATA} *.otf ${FONTDIR}

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
