PORTNAME=	gsd
DISTVERSION=	5.0.1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GSD (General Simulation Data) file format for Python
WWW=		https://bitbucket.org/glotzer/gsd/wiki/Home

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.0:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest

TEST_WRKSRC=	${WRKSRC}/gsd/test
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 5.0.1: 151 passed, 1 warning in 13.30s

.include <bsd.port.mk>
