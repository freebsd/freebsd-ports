# New ports collection makefile for:   v8
# Date created:        12 November 2010
# Whom:                siasia
#
# $FreeBSD$
#

PORTNAME=	v8
PORTVERSION=	3.3.8
CATEGORIES=	lang
MASTER_SITES=	http://github.com/${PORTNAME}/${PORTNAME}/tarball/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTNAME}-${PORTVERSION}-${GITVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Google\'s open source JavaScript engine

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

GITVERSION=	0-g1a3419a
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-1a3419a
USE_SCONS=	yes
OPTIONS=	DEBUG "Build in debug mode" Off \
		SNAPSHOT "Enable snapshots" Off \
		SHARED "Build shared library" Off

.include <bsd.port.options.mk>

SCONS_ARGS=
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

.if defined(WITH_SHARED)
USE_LDCONFIG=	yes
PLIST_SUB+=	V8SHARED=""
.else
PLIST_SUB+=	V8SHARED="@comment "
.endif

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
V8ARCH=ia32
.elif ${ARCH} == amd64
V8ARCH=x64
.endif
PLIST_SUB+=	ARCH=${V8ARCH}
SCONS_ARGS+=	arch=${V8ARCH}

do-build:
	@cd ${BUILD_WRKSRC} && \
	${SETENV} ${SCONS_BUILDENV} ${SCONS_BIN} ${SCONS_ENV} ${_MAKE_JOBS} \
	${SCONS_ARGS} library=static ${SCONS_TARGET}
.if defined(WITH_SHARED)
	@cd ${BUILD_WRKSRC} && \
	${SETENV} ${SCONS_BUILDENV} ${SCONS_BIN} ${SCONS_ENV} ${_MAKE_JOBS} \
	${SCONS_ARGS} library=shared ${SCONS_TARGET}
.endif

do-install:
	${INSTALL_DATA} -m 755 ${WRKSRC}/libv8.a ${PREFIX}/lib
	${INSTALL_DATA} -m 755 ${WRKSRC}/libv8preparser.a ${PREFIX}/lib
.if defined(WITH_SHARED)
	${INSTALL_LIB} -m 755 ${WRKSRC}/libv8.so ${PREFIX}/lib/libv8.so.1
	${INSTALL_LIB} -m 755 ${WRKSRC}/libv8preparser.so ${PREFIX}/lib/libv8preparser.so.1
.endif
	${INSTALL_DATA} ${WRKSRC}/include/v8.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-debug.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-preparser.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-profiler.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8-testing.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/v8stdint.h ${PREFIX}/include/

.include <bsd.port.post.mk>
