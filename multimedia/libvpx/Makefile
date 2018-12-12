# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvpx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0
PORTREVISION=	3
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	VP8/VP9 Codec SDK

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nasm:devel/nasm

USE_GITHUB=	yes
GH_ACCOUNT=	webmproject

USES=		compiler:c++11-lib cpe gmake perl5 shebangfix
CPE_VENDOR=	john_koleszar
HAS_CONFIGURE=	yes
USE_PERL5=	build
USE_LDCONFIG=	yes
SHEBANG_FILES=	build/make/ads2gas.pl
CONFIGURE_ENV=	ASFLAGS="${ASFLAGS}"
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--disable-install-docs \
		--disable-install-srcs \
		--enable-pic \
		--enable-vp8 \
		--enable-vp9
MAKE_ARGS+=	verbose=yes
ASFLAGS+=	${ASFLAGS_${MACHINE}}
ASFLAGS_arm=	-meabi=5
ALL_TARGET=	# empty

OPTIONS_DEFINE=	DEBUG MULTIRES POSTPROC RTCPU SHARED SIZE_LIMIT TEST THREADS
OPTIONS_DEFAULT=MULTIRES POSTPROC RTCPU SHARED SIZE_LIMIT THREADS
OPTIONS_EXCLUDE_powerpcspe=RTCPU
OPTIONS_SUB=		yes

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
	@${REINPLACE_CMD} -E '/gcctarget|link_with_cc/s/gcc[[:>:]]/$${CC}/' \
		${WRKSRC}/build/make/configure.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vpx*

post-install-SHARED-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvpx.so.*.*.*

.include <bsd.port.mk>
