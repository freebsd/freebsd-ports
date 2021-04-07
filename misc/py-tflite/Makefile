PORTNAME=	tflite
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
CATEGORIES=	misc python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parse TensorFlow Lite models in Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flatbuffers>0:devel/py-flatbuffers@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	jackwish

NO_ARCH=	yes

.include <bsd.port.mk>
