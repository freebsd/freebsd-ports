PORTNAME=	frugally-deep
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.30
CATEGORIES=	misc # deep-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library to use Keras models in C++ with ease
WWW=		https://github.com/Dobiasd/frugally-deep

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

HPP_DEPENDS=	functionalplus>0:devel/functionalplus \
		nlohmann-json>0:devel/nlohmann-json
BUILD_DEPENDS=	${HPP_DEPENDS}
RUN_DEPENDS=	${HPP_DEPENDS}
xTEST_DEPENDS=	doctest>0:devel/doctest \
		${PYTHON_PKGNAMEPREFIX}keras>0:math/py-keras@${PY_FLAVOR}

USES=		cmake compiler:c++14-lang eigen:3,build,run python:test

USE_GITHUB=	yes
GH_ACCOUNT=	Dobiasd

NO_BUILD=	yes
NO_ARCH=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}

do-test: # tests are broken because they require tensorflow which is currently not available on FreeBSD
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DFDEEP_BUILD_UNITTEST:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
