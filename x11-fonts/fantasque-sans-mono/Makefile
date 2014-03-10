# $FreeBSD$

PORTNAME=	fantasque-sans-mono
PORTVERSION=	1.6.1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://openfontlibrary.org/assets/downloads/${PORTNAME}/1baf065481fd4829a407040743378130/
DISTNAME=	fantasque-sans-mono

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Programming font, designed with functionality in mind

LICENSE=	OFL11

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		zip

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
