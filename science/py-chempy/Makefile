PORTNAME=	chempy
DISTVERSION=	0.10.2
CATEGORIES=	science python # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package useful for solving problems in chemistry
WWW=		https://github.com/bjodah/chempy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dot2tex>=2.11.3:print/dot2tex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.2.3:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pulp>=1.6.8:math/py-PuLP@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyneqsys>=0.5.7:math/py-pyneqsys@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyodesys>=0.14.5:math/py-pyodesys@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=3.0.8:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}quantities>=0.12.1:science/py-quantities@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.0.1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sym>=0.3.7:math/py-sym@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.1.1:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flakes>0:devel/py-pytest-flakes@${PY_FLAVOR} \
		gsl>0:math/gsl

USES=		localbase:ldflags python # localbase and math/gsl are only for tests
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

TEST_ARGS=	--disable-plugin-autoload --ignore=build -p pytest_cov
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}pymol # https://github.com/schrodinger/pymol-open-source/issues/100

# tests as of 0.10.2: 573 passed, 28 skipped, 5 xpassed, 3454 warnings in 43.20s

.include <bsd.port.mk>
