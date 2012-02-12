# New ports collection makefile for:   v8
# Date created:        12 November 2010
# Whom:                siasia
#
# $FreeBSD$
#

PORTNAME=	v8
PORTVERSION=	3.9.5
PORTREVISION=	0
CATEGORIES=	lang
MASTER_SITES=	LOCAL/vanilla

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Google\'s open source JavaScript engine

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

USE_XZ=		yes
USE_SCONS=	yes
USE_LDCONFIG=	yes
OPTIONS=	DEBUG "Build in debug mode" Off \
		SNAPSHOT "Enable snapshots" Off

.include <bsd.port.options.mk>

SCONS_ARGS=	visibility=default

.if defined(WITHOUT_DEBUG)
SCONS_ARGS+=	mode=release
.else
SCONS_ARGS+=	mode=debug
.endif

.if defined(WITHOUT_SNAPSHOT)
SCONS_ARGS+=	snapshot=off
.else
SCONS_ARGS+=	snapshot=on
.endif

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
V8ARCH=ia32
.elif ${ARCH} == amd64
V8ARCH=x64
.endif

.if defined(CFLAGS)
CFLAGS:=	${CFLAGS:C/-fstrict-aliasing//}
.if empty(CFLAGS:M-fno-strict-aliasing)
CFLAGS+=	-fno-strict-aliasing
.endif
.endif

PLIST_SUB+=	ARCH=${V8ARCH}
SCONS_ARGS+=	arch=${V8ARCH}
SCONS_BUILDENV+= CC="${CC} ${CFLAGS}" CXX="${CXX} ${CXXFLAGS}"

do-build:
	@cd ${BUILD_WRKSRC} && \
	${SETENV} ${SCONS_BUILDENV} ${SCONS_BIN} ${SCONS_ENV} ${_MAKE_JOBS} \
	${SCONS_ARGS} library=static ${SCONS_TARGET}
	@cd ${BUILD_WRKSRC} && \
	${SETENV} ${SCONS_BUILDENV} ${SCONS_BIN} ${SCONS_ENV} ${_MAKE_JOBS} \
	${SCONS_ARGS} library=shared ${SCONS_TARGET}

do-install:
	${INSTALL_LIB} -m 755 ${WRKSRC}/libv8.a ${PREFIX}/lib/libv8.a
	${INSTALL_LIB} -m 755 ${WRKSRC}/libv8.so ${PREFIX}/lib/libv8.so.1
	${INSTALL_LIB} -m 755 ${WRKSRC}/libv8preparser.a ${PREFIX}/lib/libv8preparser.a
	${INSTALL_LIB} -m 755 ${WRKSRC}/libv8preparser.so ${PREFIX}/lib/libv8preparser.so.1
	${LN} -sf ${PREFIX}/lib/libv8.so.1 ${PREFIX}/lib/libv8.so
	${LN} -sf ${PREFIX}/lib/libv8preparser.so.1 ${PREFIX}/lib/libv8preparser.so
	${INSTALL_DATA} ${WRKSRC}/include/v8.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-debug.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-preparser.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-profiler.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-testing.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8stdint.h ${PREFIX}/include/

.include <bsd.port.post.mk>
