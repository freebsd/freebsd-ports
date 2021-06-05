PORTNAME=	libcint
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	General GTO integrals for quantum chemistry

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenblas.so:math/openblas
TEST_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyscf>0:science/py-pyscf@${PY_FLAVOR}

USES=		cmake blaslapack:openblas python:test
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sunqm

PLIST_FILES=	include/cint.h \
		include/cint_funcs.h \
		lib/libcint.so \
		lib/libcint.so.${PORTVERSION:R:R} \
		lib/libcint.so.${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e "s|numpy\\.ctypeslib\\.load_library('libcint', .*$$|numpy.ctypeslib.load_library('libcint', '${BUILD_WRKSRC}')|" \
		${WRKSRC}/testsuite/test_cint4c1e.py \
		${WRKSRC}/testsuite/test_cint.py \
		${WRKSRC}/testsuite/test_3c2e.py

do-test: # needs science/py-pyscf, pending https://github.com/pyscf/pyscf/issues/935
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DENABLE_TEST:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
