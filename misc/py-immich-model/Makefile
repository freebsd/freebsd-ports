PORTNAME=	immich-model
DISTVERSION=	0.2.0
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Runtime for the machine learning models used by Immich
WWW=		https://github.com/immich-app/ml-models

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.26:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}onnx>=1.16.1:misc/py-onnx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}onnx-ir>=0.2.1:misc/py-onnx-ir@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}onnxscript>=0.7.0:misc/py-onnxscript@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}safetensors>=0.7:misc/py-safetensors@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

USE_GITHUB=	yes
GH_ACCOUNT=	immich-app
GH_PROJECT=	ml-models
GH_TAGNAME=	8bf3fd1b44b0

NO_ARCH=	yes

.include <bsd.port.mk>
