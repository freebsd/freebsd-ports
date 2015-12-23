# $FreeBSD$

PORTNAME=	alegreya-sans
PORTVERSION=	1.002.20150827
PORTEPOCH=	1
CATEGORIES=	x11-fonts

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Humanist sans serif font with a calligraphic feeling

LICENSE=	OFL11

USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	huertatipografica
GH_PROJECT=	Alegreya-Sans
GH_TAGNAME=	4b5282d

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC}/otf && \
		${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
