PORTNAME=	frugally-deep
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.0
CATEGORIES=	misc # deep-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library to use Keras models in C++ with ease
WWW=		https://github.com/Dobiasd/frugally-deep

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

HPP_DEPENDS=	functionalplus>0:devel/functionalplus \
		nlohmann-json>0:devel/nlohmann-json
BUILD_DEPENDS=	${HPP_DEPENDS}
RUN_DEPENDS=	${HPP_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}keras>0:math/py-keras@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tensorflow>0:science/py-tensorflow@${PY_FLAVOR}
TEST_DEPENDS=	doctest>0:devel/doctest

USES=		cmake compiler:c++14-lang eigen:3,build,run python:test

USE_GITHUB=	yes
GH_ACCOUNT=	Dobiasd

NO_BUILD=	yes
NO_ARCH=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}

test-quick: # compiled files/example-* (from README) into executable test-quick
	@${MKDIR} ${TEST_WRKSRC}/test-quick && \
		cd ${TEST_WRKSRC}/test-quick && \
		${ECHO} "Creating Keras model and converting it to frugally-deep format ..." && \
		${PYTHON_CMD} ${FILESDIR}/example-create-model.py && \
		${PYTHON_CMD} ${WRKSRC}/keras_export/convert_model.py keras_model.keras fdeep_model.json && \
		${ECHO} "Compiling example-run.cpp ..." && \
		${CXX} ${CXXFLAGS} \
			-I${STAGEDIR}${LOCALBASE}/include \
			-I${LOCALBASE}/include \
			-I${LOCALBASE}/include/eigen3 \
			${FILESDIR}/example-run.cpp \
			-o test-quick && \
		${ECHO} "Running test-quick ..." && \
		./test-quick

do-test: # tests fail to compile, see https://github.com/Dobiasd/frugally-deep/issues/462
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DFDEEP_BUILD_UNITTEST:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
