PORTNAME=	shotcut
DISTVERSION=	22.06.23
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-src-${DISTVERSION:C/\.//g}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Free, open source, cross-platform video editor

LICENSE=	GPLv3

LIB_DEPENDS=	libfftw3.so:math/fftw3
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		${LOCALBASE}/lib/libjack.so:audio/jack

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gl mlt:7 pkgconfig \
		qmake:no_env qt:5 sdl shared-mime-info tar:txz xorg
CPE_VENDOR=	meltytech

GH_ACCOUNT=	mltframework

USE_GL=	gl
USE_QT=		core declarative gui multimedia network opengl quickcontrols2 sql \
		websockets widgets xml buildtools_build concurrent_build linguisttools_build
USE_SDL=	sdl2
USE_XORG=	x11
# Needed to be able to correctly check for updates in-app.
CMAKE_ARGS=	-D${PORTNAME:tu}_VERSION="${DISTVERSION}"

WRKSRC=	${WRKDIR}/src
WRKSRC_SUBDIR=	${PORTNAME}

OPTIONS_DEFINE=	FREI0R LADSPA NLS
OPTIONS_DEFAULT=FREI0R LADSPA
OPTIONS_SUB=	yes

FREI0R_RUN_DEPENDS=	frei0r-plugins>=0:graphics/frei0r-plugins

LADSPA_RUN_DEPENDS=	swhplugins>=0:audio/swhplugins

.include <bsd.port.mk>
