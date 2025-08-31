PORTNAME=	onnx
DISTVERSION=	1.17.0
PORTREVISION=	2
CATEGORIES=	misc # machine-learning
MASTER_SITES=	PYPI \
		https://github.com/abseil/abseil-cpp/archive/refs/tags/:abseil \
		https://github.com/protocolbuffers/protobuf/releases/download/v22.3/:protobuf # use downloaded protobuf-22.3
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		20230125.3.tar.gz:abseil \
		protobuf-22.3.tar.gz:protobuf # use downloaded protobuf-22.3
DIST_SUBDIR=	onnx
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Neural Network eXchange
WWW=		https://onnx.ai \
		https://github.com/onnx/onnx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		cmake:devel/cmake-core \
		protoc-gen-mypy:devel/py-mypy-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
#LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libprotobuf.so:devel/protobuf # disable packaged protobuf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-re2>0:devel/py-google-re2@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.20.2:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.6.2.1:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR}

USES=		compiler:c++17-lang python shebangfix
USE_PYTHON=	pep517 concurrent autoplist pytest

CXXFLAGS+=	-Dstat64=stat

SHEBANG_FILES=	tools/protoc-gen-mypy.sh.in

CONFLICTS_BUILD=	protobuf # use downloaded protobuf-22.3

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/onnx/test

BINARY_ALIAS=	python=${PYTHON_CMD}

post-patch: # replace protobuf-24+ with protobuf-lite-22.3
	@${REINPLACE_CMD} \
		-e ' \
			s|set(ProtobufURL https://github.com/protocolbuffers/protobuf/releases/download/v22.3/|set(ProtobufURL file://${DISTDIR}/${DIST_SUBDIR}/|; \
			s|set(AbseilURL https://github.com/abseil/abseil-cpp/archive/refs/tags/|set(AbseilURL file://${DISTDIR}/${DIST_SUBDIR}/| \
		' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/onnx/onnx_cpp2py_export*.so

# tests as of 1.17.0: 4 failed, 4564 passed, 3044 skipped, 26 warnings in 60.66s (0:01:00), see https://github.com/onnx/onnx/issues/6733

.include <bsd.port.mk>
