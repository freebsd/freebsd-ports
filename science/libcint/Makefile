PORTNAME=	libcint
DISTVERSIONPREFIX=	v
DISTVERSION=	6.1.3
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	General GTO integrals for quantum chemistry
WWW=		https://github.com/sunqm/libcint

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

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
		#lib/libcint.so.${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e "s|\\.\\./\\.\\./build/libcint\\.so|${BUILD_WRKSRC}/libcint.so|" \
		${WRKSRC}/testsuite/test_3c2e.py
	@${REINPLACE_CMD} -e "s|os\\.path\\.abspath(os\\.path\\.join(__file__, '\\.\\./\\.\\./build/libcint\\.so'))|'${BUILD_WRKSRC}/libcint.so'|" \
		${WRKSRC}/testsuite/test_cint.py

do-test: # needs science/py-pyscf, pending https://github.com/pyscf/pyscf/issues/935
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DENABLE_TEST:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

# tests as of 6.1.3: 100% tests passed, 0 tests failed out of 2

.include <bsd.port.mk>
