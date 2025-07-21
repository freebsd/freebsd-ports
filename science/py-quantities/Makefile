PORTNAME=	quantities
DISTVERSION=	0.16.2
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Support for physical quantities with units, based on numpy
WWW=		https://github.com/python-quantities/python-quantities

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://github.com/python-quantities/python-quantities/issues/224

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/quantities/tests

NO_ARCH=	yes

# tests as of 0.16.2: 175 passed, 3 xfailed in 30.81s

.include <bsd.port.mk>
