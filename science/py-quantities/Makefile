PORTNAME=	quantities
DISTVERSION=	0.17.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Support for physical quantities with units, based on numpy
WWW=		https://github.com/python-quantities/python-quantities

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://github.com/python-quantities/python-quantities/issues/224

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/quantities/tests
TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

# tests as of 0.17.0: 1 failed, 220 passed, 3 xfailed, 475 subtests passed in 1.01s

.include <bsd.port.mk>
