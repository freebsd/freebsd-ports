PORTNAME=	textdistance
PORTVERSION=	4.6.3
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Comparing distance between two or more sequences by many algorithms
WWW=		https://github.com/life4/textdistance

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}flake8>0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR}

USES=		python
# Tests (18 failed, 180 passed)
# tests/test_external.py: RuntimeError (Levenshtein, DamerauLevenshtein, and Hamming)
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
