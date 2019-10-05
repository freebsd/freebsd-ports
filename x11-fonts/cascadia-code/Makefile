# $FreeBSD$

PORTNAME=	cascadia-code
DISTVERSION=	1910.04
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/microsoft/cascadia-code/releases/download/v${DISTVERSION}/
DISTFILES=	Cascadia.ttf
DIST_SUBDIR=	cascadia-code-${DISTVERSION}
EXTRACT_ONLY=

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Monospaced font with programming ligatures

LICENSE=	OFL11

USES=		fonts
NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	${FONTSDIR}/Cascadia.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Cascadia.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
