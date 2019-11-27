# $FreeBSD$

PORTNAME=	cascadia-code
DISTVERSION=	1911.21
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/microsoft/cascadia-code/releases/download/v${DISTVERSION}/
DISTFILES=	Cascadia.ttf \
		CascadiaMono.ttf \
		CascadiaMonoPL.ttf \
		CascadiaPL.ttf
DIST_SUBDIR=	${DISTNAME}
EXTRACT_ONLY=

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Monospaced font with programming ligatures

LICENSE=	OFL11

USES=		fonts
NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	${DISTFILES:S,^,${FONTSDIR}/,}

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${DISTFILES} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
