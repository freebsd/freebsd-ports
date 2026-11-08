PORTNAME=	docling-metrics-chemistry
DISTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chemistry evaluation metrics (SMILES, Markush) for Docling metrics
WWW=		https://github.com/docling-project/docling-metrics

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docling-metrics-core>=0.0.1:textproc/py-docling-metrics-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.24:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.12.5:devel/py-pydantic2@${PY_FLAVOR} \
		rdkit>=2024.3.1:science/rdkit

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
