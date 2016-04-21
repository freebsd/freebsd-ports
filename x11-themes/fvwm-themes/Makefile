# Created by: Oyvind Albrigtsen
# $FreeBSD$

PORTNAME=	fvwm-themes
PORTVERSION=	0.7.0
PORTREVISION=	6
CATEGORIES=	x11-themes
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-extra-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Themes for the Fvwm2 window manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	gm4:devel/m4 \
		fvwm2:x11-wm/fvwm2
RUN_DEPENDS=	fvwm2:x11-wm/fvwm2

USE_XORG=	xpm
USES=		gmake perl5 shebangfix tar:bzip2
SHEBANG_FILES=	themes/cde/modules/create-buttonbar-config \
		themes/redmondxp/modules/FvwmThemesPanelManager
GNU_CONFIGURE=	yes
NO_ARCH=	yes

post-install:
	@cd ${WRKDIR}/${PORTNAME}-extra-${PORTVERSION} && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${PREFIX}/share/fvwm/themes

.include <bsd.port.mk>
