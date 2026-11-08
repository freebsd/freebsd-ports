PORTNAME=	pyberny
DISTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	science # chemistry
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Optimizer of molecular geometries with respect to the total energy
WWW=		https://github.com/jhrmnn/pyberny

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-dynamic-versioning>0:devel/py-poetry-dynamic-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}molsym>=0.2.1:science/py-molsym@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	pep517 concurrent autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

MAKE_ENV=	POETRY_DYNAMIC_VERSIONING_BYPASS=${DISTVERSION}

# tests as of 0.7.0: 219 passed, 7 skipped in 0.71s

.include <bsd.port.mk>
