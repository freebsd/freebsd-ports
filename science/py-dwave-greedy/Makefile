PORTNAME=	dwave-greedy
DISTVERSION=	0.2.5
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Greedy binary quadratic model solvers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>0:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=1.0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYNUMPY}
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.30.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dwave-system>0:science/py-dwave-system@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils cython autoplist unittest

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/greedy/descent${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
