PORTNAME=	onnx
DISTVERSION=	1.14.1
PORTREVISION=	1
CATEGORIES=	misc # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Neural Network eXchange
WWW=		https://onnx.ai/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		cmake:devel/cmake-core \
		protoc-gen-mypy:devel/py-mypy-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR}
LIB_DEPENDS=	libprotobuf.so:devel/protobuf
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.6.2.1:devel/py-typing-extensions@${PY_FLAVOR}

USES=		compiler:c++17-lang python shebangfix
USE_PYTHON=	distutils concurrent autoplist

CXXFLAGS+=	-Dstat64=stat

SHEBANG_FILES=	tools/protoc-gen-mypy.sh.in

BINARY_ALIAS=	python=${PYTHON_CMD}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/onnx/onnx_cpp2py_export*.so

.include <bsd.port.mk>
