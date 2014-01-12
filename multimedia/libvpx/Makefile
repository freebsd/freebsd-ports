# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvpx
PORTVERSION=	1.3.0
CATEGORIES=	multimedia
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${DISTVERSION}.orig

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	VP8/VP9 Codec SDK

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		yasm:${PORTSDIR}/devel/yasm

USES=		gmake perl5
USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_PERL5=	build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG POSTPROC RUNTIME THREADS SHARED
OPTIONS_DEFAULT=	POSTPROC RUNTIME THREADS SHARED
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
.else
IGNORE=	no support for ${ARCH} the moment. testing/patches are welcome
.endif

post-patch:
	@${REINPLACE_CMD} 's|\(link_with_cc\)=gcc|\1=$${CC}|' \
		${WRKSRC}/build/make/configure.sh
	@${REINPLACE_CMD} -e 's|%%DESTDIR%%|${STAGEDIR}|g' \
	       	${WRKSRC}/build/make/Makefile ${WRKSRC}/libs.mk
	@${GREP} -Rl '^#!/bin/bash' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		-e 's,#!/bin/bash,#!/usr/bin/env bash,g'
	@${GREP} -Rl -- '-l\?pthread' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} -E \
		-e 's/-l?pthread/${PTHREAD_LIBS}/g'

.include <bsd.port.mk>
