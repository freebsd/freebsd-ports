PORTNAME=	pytorch-lightning
DISTVERSION=	2.6.1
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight PyTorch wrapper for ML researchers
WWW=		https://lightning.ai/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fsspec>=2022.5.0:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lightning-utilities>=0.10.0:misc/py-lightning-utilities@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy1>=1.16:math/py-numpy1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.1.0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchmetrics>=0.7.0:misc/py-torchmetrics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.57.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>5.4:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

WRKSRC=		${WRKDIR}/pytorch_lightning-${DISTVERSION}

NO_ARCH=	yes

.include <bsd.port.mk>
