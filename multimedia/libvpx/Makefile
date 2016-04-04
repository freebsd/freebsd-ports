# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvpx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	VP8/VP9 Codec SDK

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	yasm:devel/yasm

USE_GITHUB=	yes
GH_ACCOUNT=	webmproject

USES=		compiler cpe gmake perl5 shebangfix tar:bzip2
CPE_VENDOR=	john_koleszar
HAS_CONFIGURE=	yes
USE_PERL5=	build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG MULTIRES POSTPROC RUNTIME SHARED SIZE_LIMIT THREADS
OPTIONS_DEFAULT=MULTIRES POSTPROC RUNTIME SHARED SIZE_LIMIT THREADS
OPTIONS_EXCLUDE_aarch64=RUNTIME
OPTIONS_EXCLUDE_armv6=	RUNTIME
MULTIRES_DESC=	Enable multi-resolution encoding
POSTPROC_DESC=	Enable postprocessing
RUNTIME_DESC=	Enable runtime CPU detection
SHARED_DESC=	Enable shared-library support
SIZE_LIMIT_DESC=Maximum size allowed by decoder: ${SIZE_LIMIT}

ALL_TARGET=
CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--disable-install-docs \
		--disable-install-srcs \
		--enable-pic \
		--enable-vp8 \
		--enable-vp9
MAKE_ARGS+=	verbose=yes
MAKE_ENV=	LC_ALL=C

OPTIONS_SUB=		SHARED

DEBUG_CONFIGURE_ON=	--enable-debug
MULTIRES_CONFIGURE_ON=	--enable-multi-res-encoding
POSTPROC_CONFIGURE_ON=	--enable-postproc --enable-vp9-postproc	\
			--enable-vp9-temporal-denoising
RUNTIME_CONFIGURE_ON=	--enable-runtime-cpu-detect
SHARED_CONFIGURE_ON=	--enable-shared
SIZE_LIMIT_CONFIGURE_ON=--size-limit=${SIZE_LIMIT}
SIZE_LIMIT?=		16384x16384 # Chromium; Firefox has 4000x3000
THREADS_CONFIGURE_OFF=	--disable-multithread

SHEBANG_FILES=	build/make/ads2gas.pl

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 1000000
CONFIGURE_ARGS+=	--disable-unit-tests
.endif

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--target=x86_64-linux-gcc
.elif ${ARCH} == "i386"
CONFIGURE_ARGS+=	--target=x86-linux-gcc
.elif ${ARCH} == "ia64"
CONFIGURE_ARGS+=	--target=ia64-linux-gcc
.elif ${ARCH} == "powerpc"
CONFIGURE_ARGS+=	--target=ppc32-linux-gcc
.elif ${ARCH} == "powerpc64"
CONFIGURE_ARGS+=	--target=ppc64-linux-gcc
.elif ${ARCH} == "sparc64"
CONFIGURE_ARGS+=	--target=sparc64-linux-gcc
USES:=			${USES:Ncompiler*} compiler:c++11-lib
.elif ${ARCH} == "aarch64"
CONFIGURE_ARGS+=	--target=arm64-linux-gcc
.elif ${ARCH} == "armv6"
CONFIGURE_ARGS+=	--target=armv6-linux-gcc --cpu=armv6
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-build_make_Makefile
.else
IGNORE=	no support for ${ARCH} the moment. testing/patches are welcome
.endif

.include <bsd.port.pre.mk>

# Workaround for GCC in 9.x post r260075
# OSVERSION taken from r260135, the closest OSVERSION
.if ${OPSYS} == FreeBSD && ${OSVERSION} > 902505
. if ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} == 42
CFLAGS+=	-flax-vector-conversions
. endif
.endif

post-patch:
	@${REINPLACE_CMD} 's|\(link_with_cc\)=gcc|\1=$${CC}|' \
		${WRKSRC}/build/make/configure.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vpx*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvpx.so.*.*.*

.include <bsd.port.post.mk>
