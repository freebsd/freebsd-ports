# $FreeBSD$

PORTNAME=	cosmic-sans-neue-mono
PORTVERSION=	1.3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://openfontlibrary.org/assets/downloads/${PORTNAME}/bf42dd6dc411076a2dfc12aa6cf60e7d/
DISTNAME=	${PORTNAME}

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Programming font, designed with functionality in mind

LICENSE=	OFL11

NO_BUILD=	yes
USE_ZIP=	yes

FONTDIR=	${STAGEDIR}${PREFIX}/lib/X11/fonts/${PORTNAME}
WRKSRC=		${WRKDIR}

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${FONTDIR}
	cd ${WRKSRC}/OTF && \
		${INSTALL_DATA} *.otf ${FONTDIR}

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
