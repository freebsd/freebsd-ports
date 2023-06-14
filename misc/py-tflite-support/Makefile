PORTNAME=	tflite-support
DISTVERSION=	0.1.0a1
PORTREVISION=	1
CATEGORIES=	misc # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Toolkit for developing/deploying ML/TFLite models
WWW=		https://www.tensorflow.org/

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>=2.4:devel/py-pybind11@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}absl>=0.7.0:devel/py-absl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.4:devel/py-pybind11@${PY_FLAVOR}

USES=		compiler:c++14-lang python
USE_PYTHON=	distutils concurrent autoplist

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
