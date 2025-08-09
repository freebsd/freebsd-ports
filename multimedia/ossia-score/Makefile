PORTNAME=	ossia-score # uses -mcx16
DISTVERSION=	3.4.1
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
#BUILD_DEPENDS+=	concurrentqueue>0:devel/concurrentqueue # broken, see https://github.com/ossia/score/issues/1720
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libavcodec.so:multimedia/ffmpeg \
		libboost_system.so:devel/boost-libs \
		libfaust.so:audio/faust \
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

USES=		cmake gl localbase:ldflags llvm:19 pkgconfig qt:6 sdl tar:xz
USE_GL=		gl opengl
USE_QT=		base declarative scxml serialport shadertools svg websockets
USE_SDL=	sdl2

CMAKE_ON=	SCORE_USE_SYSTEM_LIBRARIES \
		BUILD_SHARED_LIBS
CMAKE_ARGS=	-DSCORE_DISABLED_PLUGINS="score-plugin-pd;score-plugin-vst3" \
		-DCMAKE_CXX_FLAGS="-fexperimental-library" \
		-DCMAKE_UNITY_BUILD=1
#CMAKE_ARGS+=	-DCMAKE_MODULE_PATH=${LLVM_PREFIX}/lib/cmake/clang # JIT plugin fails to build, see https://github.com/ossia/score/issues/1721

CXXFLAGS+=	-fexperimental-library # to fix libossia/src/ossia/detail/jthread.hpp:10:8: error: Rebuild with -fexperimental-library, clang 18 ships headers which are incompatible with this file but hides half of them behind that flag

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
PLIST_FILES=	lib/libkfr_dft_avx.a \
		lib/libkfr_dft_avx2.a \
		lib/libkfr_dft_avx512.a \
		lib/libkfr_dft_sse2.a \
		lib/libkfr_dft_sse41.a \
		lib/libkfr_dsp_avx.a \
		lib/libkfr_dsp_avx2.a \
		lib/libkfr_dsp_avx512.a \
		lib/libkfr_dsp_sse2.a \
		lib/libkfr_dsp_sse41.a
.endif

.include <bsd.port.post.mk>
