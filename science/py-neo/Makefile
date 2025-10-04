PORTNAME=	neo
PORTVERSION=	0.14.2
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for representing electrophysiology data in Python
WWW=		https://neo.readthedocs.io/en/latest/ \
		https://github.com/NeuralEnsemble/python-neo

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}quantities>=0.16.1:science/py-quantities@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent pytest

NO_ARCH=	yes

# tests as of 0.14.2: 669 passed, 731 skipped in 80.29s

.include <bsd.port.mk>
