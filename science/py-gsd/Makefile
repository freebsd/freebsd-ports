PORTNAME=	gsd
DISTVERSION=	3.4.1
PORTREVISION=	3
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GSD (General Simulation Data) file format for Python
WWW=		https://bitbucket.org/glotzer/gsd/wiki/Home

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist pytest

TEST_WRKSRC=	${WRKSRC}/gsd/test
#TEST_ARGS=	--pyargs gsd -p gsd.pytest_plugin_validate --validate # enable this line to run longer tests, see https://gsd.readthedocs.io/en/v2.6.0/installation.html#run-tests
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-extract: # force cythonization because pre-cythonized fl.c fails to complile
	@${RM} ${WRKSRC}/gsd/fl.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/gsd/fl*.so

.include <bsd.port.mk>
