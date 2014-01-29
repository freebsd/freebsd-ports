# $FreeBSD$

PORTNAME=	alegreya-sans
PORTVERSION=	1.002
PORTEPOCH=	1
CATEGORIES=	x11-fonts

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Humanist sans serif font with a calligraphic feeling

LICENSE=	OFL11

USE_GITHUB=	yes
GH_ACCOUNT=	juandelperal
GH_PROJECT=	Alegreya-Sans
GH_TAGNAME=	2d2a4b0
GH_COMMIT=	2d2a4b0

NO_BUILD=	yes

FONTDIR=	${STAGEDIR}${PREFIX}/lib/X11/fonts/${PORTNAME}

do-install:
	${MKDIR} ${FONTDIR}
	cd ${WRKSRC}/otf && \
		${INSTALL_DATA} *.otf ${FONTDIR}

.include <bsd.port.mk>
