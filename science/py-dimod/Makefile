PORTNAME=	dimod
DISTVERSION=	0.12.21
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Shared API for QUBO/Ising samplers
WWW=		https://github.com/dwavesystems/dimod

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>0:devel/py-mypy@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	autoplist cython3 distutils unittest

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} -name "*${PYTHON_TAG}.so" | ${XARGS} ${STRIP_CMD}

# tests as of 0.12.21: Ran 2914 tests in 35.706s

.include <bsd.port.mk>
