# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvpx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	VP8/VP9 Codec SDK

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	yasm:devel/yasm

USE_GITHUB=	yes
GH_ACCOUNT=	webmproject

USES=		compiler:c11 cpe gmake perl5 shebangfix
CPE_VENDOR=	john_koleszar
HAS_CONFIGURE=	yes
USE_PERL5=	build
USE_LDCONFIG=	yes
SHEBANG_FILES=	build/make/ads2gas.pl
CONFIGURE_ENV=	ASFLAGS="${ASFLAGS}"
# Only explicitly list ARCHs with SIMD optimizations
CONFIGURE_ARGS_aarch64=	--target=arm64-linux-gcc
CONFIGURE_ARGS_amd64=	--target=x86_64-linux-gcc
CONFIGURE_ARGS_i386=	--target=x86-linux-gcc
.if ${CFLAGS:M-march=armv[78]*}
CONFIGURE_ARGS+=	--target=armv7-linux-gcc
ASFLAGS+=		-meabi=5
.endif
CONFIGURE_ARGS+=${CONFIGURE_ARGS_${ARCH}} \
		--prefix=${PREFIX} \
		--disable-install-docs \
		--disable-install-srcs \
		--enable-pic \
		--enable-vp8 \
		--enable-vp9
MAKE_ARGS+=	verbose=yes
ALL_TARGET=	# empty

OPTIONS_DEFINE=	DEBUG MULTIRES POSTPROC RTCPU SHARED SIZE_LIMIT TEST THREADS
OPTIONS_DEFAULT=MULTIRES POSTPROC RTCPU SHARED SIZE_LIMIT THREADS
OPTIONS_EXCLUDE_aarch64=RTCPU
OPTIONS_EXCLUDE_armv6=	RTCPU
OPTIONS_SUB=		SHARED

DEBUG_CONFIGURE_ON=	--enable-debug

MULTIRES_DESC=		Enable multi-resolution encoding
MULTIRES_CONFIGURE_ON=	--enable-multi-res-encoding

POSTPROC_DESC=		Enable postprocessing
POSTPROC_CONFIGURE_ON=	--enable-postproc --enable-vp9-postproc	\
			--enable-vp9-temporal-denoising

RTCPU_DESC=		Detect CPU capabilities at runtime
RTCPU_CONFIGURE_ON=	--enable-runtime-cpu-detect

SHARED_DESC=		Enable shared-library support
SHARED_CONFIGURE_ON=	--enable-shared

SIZE_LIMIT_DESC=	Maximum size allowed by decoder: ${SIZE_LIMIT}
SIZE_LIMIT_CONFIGURE_ON=--size-limit=${SIZE_LIMIT}
SIZE_LIMIT?=		16384x16384 # Chromium; Firefox has 4000x3000

TEST_CONFIGURE_OFF=	--disable-unit-tests

THREADS_CONFIGURE_OFF=	--disable-multithread

post-patch:
	@${REINPLACE_CMD} 's|\(link_with_cc\)=gcc|\1=$${CC}|' \
		${WRKSRC}/build/make/configure.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vpx*

post-install-SHARED-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvpx.so.*.*.*

.include <bsd.port.mk>
