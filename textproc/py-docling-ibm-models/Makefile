PORTNAME=	docling-ibm-models
DISTVERSION=	4.0.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	AI models used by the Docling PDF conversion package
WWW=		https://github.com/docling-project/docling-ibm-models

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}accelerate>=1.2.1:misc/py-accelerate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-core>=2.95.0:textproc/py-docling-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}huggingface-hub>=0.23:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonlines>=3.1.0:devel/py-jsonlines@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.24.4:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.2.2:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rtree>=1.0.0:devel/py-rtree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}safetensors>=0.4.3:misc/py-safetensors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchvision>=0:misc/py-torchvision@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.64.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=4.42.0:misc/py-transformers@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
