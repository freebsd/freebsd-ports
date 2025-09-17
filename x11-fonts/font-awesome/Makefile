PORTNAME=	font-awesome
DISTVERSION=	7.0.1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://use.fontawesome.com/releases/v${DISTVERSION}/ \
		https://github.com/FortAwesome/Font-Awesome/releases/download/${DISTVERSION}/
DISTNAME=	fontawesome-free-${DISTVERSION}-desktop

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Suite of pictographic icons from Font Awesome (free version)
WWW=		https://fontawesome.com/ \
		https://github.com/FortAwesome/Font-Awesome/

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes

VER=		${DISTVERSION:R:R}
SUB_FILES=	pkg-message
SUB_LIST=	VER=${VER}
PLIST_FILES=	${FONTSDIR}/Font\ Awesome\ ${VER}\ Brands-Regular-400.otf \
		${FONTSDIR}/Font\ Awesome\ ${VER}\ Free-Regular-400.otf \
		${FONTSDIR}/Font\ Awesome\ ${VER}\ Free-Solid-900.otf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/otfs/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
