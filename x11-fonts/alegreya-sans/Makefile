# $FreeBSD$

PORTNAME=	alegreya-sans
PORTVERSION=	1.002
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-fonts

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Humanist sans serif font with a calligraphic feeling

LICENSE=	OFL11

USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	juandelperal
GH_PROJECT=	Alegreya-Sans
GH_TAGNAME=	2d2a4b0

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC}/otf && \
		${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
