PORTNAME=	primecount
DISTVERSIONPREFIX=	v
DISTVERSION=	7.20
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Fast prime counting function implementations
WWW=		https://github.com/kimwalisch/primecount

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	libdivide>0:math/libdivide
LIB_DEPENDS=	libprimesieve.so:math/primesieve

USE_GITHUB=	yes
GH_ACCOUNT=	kimwalisch

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_LIBPRIMESIEVE BUILD_STATIC_LIBS

.if !exists(/usr/local/omp.h)
CMAKE_OFF+=	WITH_OPENMP
.endif

PLIST_SUB=	VER=${PORTVERSION}

do-test:
	cd ${BUILD_WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
