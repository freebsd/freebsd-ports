PORTNAME=	ossia-score # uses -mcx16
DISTVERSION=	3.3.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/ossia/score/releases/download/v${DISTVERSION}/
DISTFILES=	ossia.score-${DISTVERSION}-src${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive sequencer for the intermedia arts
WWW=		https://ossia.io/ \
		https://github.com/ossia/score

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	rapidfuzz-cpp>0:devel/rapidfuzz-cpp
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libboost_system.so:devel/boost-libs \
		libfftw3.so:math/fftw3 \
		libfmt.so:devel/libfmt \
		libhdf5.so:science/hdf5 \
		libportaudio.so:audio/portaudio \
		libre2.so:devel/re2 \
		libsamplerate.so:audio/libsamplerate \
		libsnappy.so:archivers/snappy \
		libsndfile.so:audio/libsndfile \
		libspdlog.so:devel/spdlog \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++20-lang gl pkgconfig qt:6 tar:xz
USE_GL=		gl opengl
USE_QT=		base declarative scxml serialport shadertools svg websockets

CMAKE_ON=	SCORE_USE_SYSTEM_LIBRARIES \
		BUILD_SHARED_LIBS
CMAKE_ARGS=	-DSCORE_DISABLED_PLUGINS="score-plugin-pd;score-plugin-vst3" \
		-DCMAKE_CXX_FLAGS="-fexperimental-library" \
		-DCMAKE_UNITY_BUILD=1

.include <bsd.port.mk>
