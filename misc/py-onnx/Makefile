# $FreeBSD$

PORTNAME=	onnx
DISTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	misc # machine-learning
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Neural Network eXchange

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR}
LIB_DEPENDS=	libprotobuf.so:devel/protobuf
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PY_TYPING} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		compiler:c11 python
USE_PYTHON=	distutils concurrent autoplist

BINARY_ALIAS=	python=${PYTHON_CMD}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/onnx/onnx_cpp2py_export.so

.include <bsd.port.mk>
