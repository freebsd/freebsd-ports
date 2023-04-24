PORTNAME=	formulaic
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	math python # statistics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of Wilkinson formulas
WWW=		https://github.com/matthewwardrop/formulaic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astor>=0.8:devel/py-astor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cached-property>=1.3.0:devel/py-cached-property@${PY_FLAVOR} \
		${PYNUMY} \
		${PYTHON_PKGNAMEPREFIX}interface-meta>=1.2.0:devel/py-interface-meta@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.6:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.2.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.0:devel/py-wrapt@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}installer>0:devel/py-installer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>=1.3:math/py-sympy@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	pep517 autoplist pytest # 2 tests fail, see https://github.com/matthewwardrop/formulaic/issues/140

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
