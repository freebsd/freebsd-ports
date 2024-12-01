PORTNAME=	shotcut
DISTVERSION=	24.11.17
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/mltframework/${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	-qt6
DISTNAME=	${PORTNAME}-src-${DISTVERSION:C/\.//g}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Free, open source, cross-platform video editor
WWW=		https://shotcut.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libfftw3.so:math/fftw3
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		${LOCALBASE}/lib/libjack.so:audio/jack \
		${LOCALBASE}/lib/mlt-7/libmltglaxnimate-qt6.so:multimedia/mlt7-glaxnimate@qt6 \
		${LOCALBASE}/lib/mlt-7/libmltqt6.so:multimedia/mlt7-qt@qt6

USES=		cmake compiler:c++17-lang cpe desktop-file-utils gl mlt:7 \
		pkgconfig qt:6 sdl shared-mime-info tar:txz xorg
CPE_VENDOR=	meltytech
USE_GL=		opengl
USE_QT=		base charts declarative multimedia tools:build
USE_SDL=	sdl2
USE_XORG=	x11

# Disable upgrade notifications for the ports ecosystem.
CXXFLAGS+=	-DSHOTCUT_NOUPGRADE

CONFLICTS=	shotcut

SUB_FILES=	${PORTNAME}.sh

WRKSRC=		${WRKDIR}/src
WRKSRC_SUBDIR=	${PORTNAME}

OPTIONS_DEFINE=	FREI0R LADSPA
OPTIONS_DEFAULT=FREI0R LADSPA

FREI0R_RUN_DEPENDS=	frei0r-plugins>=0:graphics/frei0r-plugins

LADSPA_RUN_DEPENDS=	swhplugins>=0:audio/swhplugins

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-real
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
