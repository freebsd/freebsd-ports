PORTNAME=	tflite
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.0
CATEGORIES=	misc python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parse TensorFlow Lite models in Python
WWW=		https://jackwish.net/tflite/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flatbuffers>0:devel/py-flatbuffers@${PY_FLAVOR} \
		${PYNUMPY}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	jackwish

NO_ARCH=	yes

.include <bsd.port.mk>
