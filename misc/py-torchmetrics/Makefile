PORTNAME=	torchmetrics
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.1
CATEGORIES=	misc python # machine-learning
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTorch native metrics
WWW=		https://lightning.ai/docs/torchmetrics/stable/ \
		https://github.com/Lightning-AI/torchmetrics

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lightning-utilities>=0.8.0:misc/py-lightning-utilities@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>=3.6:textproc/py-nltk@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>17.1:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=2021.9.24:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.0.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchvision>0:misc/py-torchvision@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.41.0:misc/py-tqdm@${PY_FLAVOR} # some optional dependencies for some sections are missing
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	Lightning-AI

NO_ARCH=	yes

.include <bsd.port.mk>
