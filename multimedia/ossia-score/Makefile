PORTNAME=	ossia-score # uses -mcx16
DISTVERSION=	3.3.2
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/ossia/score/releases/download/v${DISTVERSION}/
DISTFILES=	ossia.score-${DISTVERSION}-src${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive sequencer for the intermedia arts
WWW=		https://ossia.io/ \
		https://github.com/ossia/score

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	compilation fails, see https://github.com/ossia/score/issues/1608

BUILD_DEPENDS=	rapidfuzz-cpp>0:devel/rapidfuzz-cpp \
		rapidjson>0:devel/rapidjson \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libavcodec.so:multimedia/ffmpeg \
		libboost_system.so:devel/boost-libs \
		libfftw3.so:math/fftw3 \
		libfmt.so:devel/libfmt \
		libjack.so:audio/jack \
		libhdf5.so:science/hdf5 \
		liblilv-0.so:audio/lilv \
		libportaudio.so:audio/portaudio \
		libre2.so:devel/re2 \
		libsamplerate.so:audio/libsamplerate \
		libsnappy.so:archivers/snappy \
		libsndfile.so:audio/libsndfile \
		libspdlog.so:devel/spdlog \
		libsuil-0.so:audio/suil \
		libxkbcommon.so:x11/libxkbcommon \
		libzstd.so:archivers/zstd

USES=		cmake gl llvm:19 pkgconfig qt:6 tar:xz
USE_GL=		gl opengl
USE_QT=		base declarative scxml serialport shadertools svg websockets

CMAKE_ON=	SCORE_USE_SYSTEM_LIBRARIES \
		BUILD_SHARED_LIBS
CMAKE_ARGS=	-DSCORE_DISABLED_PLUGINS="score-plugin-pd;score-plugin-vst3" \
		-DCMAKE_CXX_FLAGS="-fexperimental-library" \
		-DCMAKE_UNITY_BUILD=1

CXXFLAGS+=	-fexperimental-library # to fix libossia/src/ossia/detail/jthread.hpp:10:8: error: Rebuild with -fexperimental-library, clang 18 ships headers which are incompatible with this file but hides half of them behind that flag

.include <bsd.port.mk>
