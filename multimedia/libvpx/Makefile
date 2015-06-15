# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvpx
PORTVERSION=	1.4.0
CATEGORIES=	multimedia
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${DISTVERSION}.orig

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	VP8/VP9 Codec SDK

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm

USES=		cpe gmake perl5 shebangfix tar:bzip2
CPE_VENDOR=	john_koleszar
HAS_CONFIGURE=	yes
USE_PERL5=	build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG POSTPROC RUNTIME THREADS SHARED
OPTIONS_DEFAULT=	POSTPROC RUNTIME THREADS SHARED
OPTIONS_EXCLUDE_armv6=	RUNTIME
POSTPROC_DESC=	Enable postprocessing
RUNTIME_DESC=	Enable runtime CPU detection
SHARED_DESC=	Enable shared-library support

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
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
POSTPROC_CONFIGURE_ON=	--enable-postproc
RUNTIME_CONFIGURE_ON=	--enable-runtime-cpu-detect
THREADS_CONFIGURE_OFF=	--disable-multithread
SHARED_CONFIGURE_ON=	--enable-shared

SHEBANG_FILES=	build/make/ads2gas.pl

.include <bsd.port.options.mk>

.if ${OSVERSION}  < 900000
.if ${ARCH} == "amd64"
USE_GCC=	yes
.endif
.endif

# Workaround for GCC in 9.x post r260075
# OSVERSION taken from r260135, the closest OSVERSION
.if ${OSVERSION} >  902505 && ${OSVERSION} < 1000000
CFLAGS+=	-flax-vector-conversions
.endif

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
.elif ${ARCH} == "armv6"
CONFIGURE_ARGS+=	--target=armv6-linux-gcc --cpu=armv6
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-build_make_Makefile
.else
IGNORE=	no support for ${ARCH} the moment. testing/patches are welcome
.endif

post-patch:
	@${REINPLACE_CMD} 's|\(link_with_cc\)=gcc|\1=$${CC}|' \
		${WRKSRC}/build/make/configure.sh

.include <bsd.port.mk>
