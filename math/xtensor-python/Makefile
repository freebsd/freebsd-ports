PORTNAME=	xtensor-python
DISTVERSION=	0.26.0
CATEGORIES=	math python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for xtensor # it is called "bindings" but it doesn't install python modules, it's rather a header-only library to use xtensor from python extensions

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

HPP_DEPENDS=	xtensor>0:math/xtensor \
		pybind11>0:devel/pybind11 \
		${PYNUMPY}
BUILD_DEPENDS=	${HPP_DEPENDS}
RUN_DEPENDS=	${HPP_DEPENDS}
TEST_DEPENDS=	googletest>0:devel/googletest \
		pybind11>0:devel/pybind11

USES=		cmake compiler:c++14-lang python

USE_GITHUB=	yes
GH_ACCOUNT=	xtensor-stack

CXXFLAGS+=	-I${PYTHON_INCLUDEDIR} -I${PYTHON_SITELIBDIR}/numpy/core/include # workaround for https://github.com/xtensor-stack/xtensor-python/issues/272

NO_BUILD=	yes
NO_ARCH=	yes

do-test: install
	@cd ${WRKSRC}/test && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} . && \
		${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} && \
		${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} xtest

.include <bsd.port.mk>
