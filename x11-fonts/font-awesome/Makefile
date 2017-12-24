# $FreeBSD$

PORTNAME=	font-awesome
DISTVERSION=	5.0.2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://use.fontawesome.com/releases/v${DISTVERSION}/
DISTNAME=	fontawesome-free-${DISTVERSION}

MAINTAINER=	dg@syrec.org
COMMENT=	Suite of pictographic icons from Font Awesome (free version)

LICENSE=	OFL11

USES=		fonts zip
NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	${FONTSDIR}/Font\ Awesome\ 5\ Brands-Regular-400.otf \
		${FONTSDIR}/Font\ Awesome\ 5\ Free-Regular-400.otf \
		${FONTSDIR}/Font\ Awesome\ 5\ Free-Solid-900.otf \
		${FONTSDIR}/fa-brands-400.ttf \
		${FONTSDIR}/fa-regular-400.ttf \
		${FONTSDIR}/fa-solid-900.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/use-on-desktop/*.otf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/web-fonts-with-css/webfonts/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
