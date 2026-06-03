PORTNAME=		funnelcake
PORTVERSION=		0.1.0
CATEGORIES=		multimedia

MAINTAINER=		toasty@dragondata.com
COMMENT=		SIMD YUV scaler with HDR/SDR tonemapping
WWW=			https://github.com/kdkd/funnelcake

LICENSE=		BSD2CLAUSEPATENT
LICENSE_NAME=		BSD 2-Clause Plus Patent License
LICENSE_FILE=		${WRKSRC}/LICENSE.md
LICENSE_PERMS=		dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	requires AVX2 (amd64) or NEON (aarch64) SIMD kernels

USES=			gmake
USE_GITHUB=		yes
GH_ACCOUNT=		kdkd

USE_LDCONFIG=		yes

OPTIONS_DEFINE=		FFMPEG OPTIMIZED
OPTIONS_SUB=		yes

FFMPEG_DESC=		Enable support for benchmarking against ffmpeg
FFMPEG_LIB_DEPENDS=	libswscale.so:multimedia/ffmpeg
FFMPEG_ALL_TARGET=	all funnelcake_test
FFMPEG_VARS=		PKGMESSAGE=${FILESDIR}/pkg-message-FFMPEG
OPTIMIZED_DESC=		Enable host-specific optimizations
OPTIMIZED_VARS=		OPTIMIZED_ENV=TUNE=native
TEST_TARGET=		test
MAKE_ENV+=		${OPTIMIZED_ENV}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfunnelcake.so.1

post-install-FFMPEG-on:
	${INSTALL_PROGRAM} ${WRKSRC}/funnelcake_test ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
