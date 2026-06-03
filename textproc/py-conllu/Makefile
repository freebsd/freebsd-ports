PORTNAME=	conllu
DISTVERSION=	6.0.0
CATEGORIES=	textproc python # machine-learning
#MASTER_SITES=	PYPI # incomplete tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CoNLL-U format parser for Python
WWW=		https://github.com/EmilStenstrom/conllu/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	EmilStenstrom

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

NO_ARCH=	yes

# tests as of 6.0.0 are incomplete
# Results (0.65s):
#      138 passed
#        1 failed
#          - tests/test_readme.py:30 test_readme

.include <bsd.port.mk>
