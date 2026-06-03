PORTNAME=	neo
PORTVERSION=	0.14.4
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for representing electrophysiology data in Python
WWW=		https://neo.readthedocs.io/en/latest/ \
		https://github.com/NeuralEnsemble/python-neo

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.25.2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}quantities>=0.16.4:science/py-quantities@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		DISPLAY=${DISPLAY} \
		XAUTHORITY=${XAUTHORITY}
TEST_WRKSRC=	${WRKSRC}/neo/test

NO_ARCH=	yes

# tests as of 0.14.4: 1 failed, 675 passed, 737 skipped, 1 warning in 11.78s

.include <bsd.port.mk>
