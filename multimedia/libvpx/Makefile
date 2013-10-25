# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvpx
PORTVERSION=	1.2.0
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	VP8 Codec SDK

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		yasm:${PORTSDIR}/devel/yasm

USES=		gmake perl5
USE_BZIP2=	yes
PROJECTHOST=	webm
HAS_CONFIGURE=	yes
USE_PERL5=	build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG POSTPROC RUNTIME THREADS SHARED
OPTIONS_DEFAULT=	POSTPROC RUNTIME THREADS SHARED
POSTPROC_DESC=	Enable postprocessing
RUNTIME_DESC=	Enable runtime CPU detection
SHARED_DESC=	Enable shared-library support

ALL_TARGET=
CONFIGURE_ARGS+=	--enable-pic --disable-install-srcs --enable-vp8 --disable-install-docs
MAKE_ARGS+=	DIST_DIR=${PREFIX} verbose=yes DESTDIR=${STAGEDIR}
MAKE_ENV=	LC_ALL=C

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 1000000
CONFIGURE_ARGS+=	--disable-unit-tests
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MPOSTPROC}
CONFIGURE_ARGS+=	--enable-postproc
.endif

.if ${PORT_OPTIONS:MRUNTIME}
CONFIGURE_ARGS+=	--enable-runtime-cpu-detect
.endif

.if ! ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--disable-multithread
.endif

.if ${PORT_OPTIONS:MSHARED}
CONFIGURE_ARGS+=	--enable-shared
PLIST_SUB+=	SHARED=""
.else
PLIST_SUB+=	SHARED="@comment "
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
