PORTNAME=	dimod
DISTVERSION=	0.12.23
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Shared API for QUBO/Ising samplers
WWW=		https://github.com/dwavesystems/dimod

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython>=3.0:lang/cython@${PY_FLAVOR} \
		meson>=1.12.0:devel/meson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}meson-python>=0.20.0:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ninja>0:devel/py-ninja@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}networkx>=3.2:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.3.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	autoplist pep517 unittest

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} -name "*${PYTHON_TAG}.so" | ${XARGS} ${STRIP_CMD}

# tests as of 0.12.23: Ran 2968 tests in 8.440s

.include <bsd.port.mk>
