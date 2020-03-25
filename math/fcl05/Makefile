# $FreeBSD$

PORTNAME=	fcl
DISTVERSION=	0.5.0
CATEGORIES=	math
PKGNAMESUFFIX=	05

MAINTAINER=	db@FreeBSD.org
COMMENT=	Flexible Collision Library (Old version)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libccd.so:math/libccd \
		liboctomap.so:math/octomap

USES=		cmake compiler:c++11-lang eigen:3 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	flexible-collision-library
GH_PROJECT=	fcl
USE_LDCONFIG=	yes

CMAKE_OFF=	FCL_BUILD_TESTS BUILD_TESTING

OPTIONS_DEFINE_amd64=		SSE2 SSE3 SSSE3 SSE4 SSE41 SSE42 SSE4A
OPTIONS_DEFAULT_amd64=		SSE2
OPTIONS_DEFINE_i386=		${OPTIONS_DEFINE_amd64}
OPTIONS_DEFAULT_i386=		${OPTIONS_DEFAULT_amd64}

.for sse in ${OPTIONS_DEFINE_amd64}
${sse}_DESC=		Support for ${sse}
${sse}_CMAKE_ON=	-DFCL_USE_X64_SSE:BOOL=ON -DOPT_SSE_${sse}=-m${sse:tl:S/41/4.1/:S/42/4.2/}
.endfor

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON -DFCL_BUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
