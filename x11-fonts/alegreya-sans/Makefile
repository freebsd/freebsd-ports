PORTNAME=	alegreya-sans
DISTVERSIONPREFIX=	v
DISTVERSION=	2.008
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-fonts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Humanist sans serif font with a calligraphic feeling
WWW=		https://www.huertatipografica.com/fonts/alegreya-sans-ht

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	huertatipografica
GH_PROJECT=	Alegreya-Sans

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC}/fonts/otf && \
		${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
