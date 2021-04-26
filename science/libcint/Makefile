PORTNAME=	libcint
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	General GTO integrals for quantum chemistry

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		cmake blaslapack:openblas
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sunqm

PLIST_FILES=	include/cint.h \
		include/cint_funcs.h \
		lib/libcint.so \
		lib/libcint.so.${PORTVERSION:R:R} \
		lib/libcint.so.${PORTVERSION}

do-test: # tests fail: https://github.com/sunqm/libcint/issues/54
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DENABLE_TEST:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
