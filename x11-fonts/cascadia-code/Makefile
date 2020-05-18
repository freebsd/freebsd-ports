# $FreeBSD$

PORTNAME=	cascadia-code
DISTVERSION=	2005.15
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/microsoft/cascadia-code/releases/download/v${DISTVERSION}/
DISTNAME=	CascadiaCode_${DISTVERSION}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Monospaced font with programming ligatures

LICENSE=	OFL11

USES=		fonts zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	${FONTSDIR}/CascadiaCode.ttf \
		${FONTSDIR}/CascadiaCodePL.ttf \
		${FONTSDIR}/CascadiaMono.ttf \
		${FONTSDIR}/CascadiaMonoPL.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf \
		${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
