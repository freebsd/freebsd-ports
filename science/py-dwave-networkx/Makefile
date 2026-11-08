PORTNAME=	dwave-networkx # dwave-networkx is being deprecated in favor of dwave-graphs, but it is still used by some packages
DISTVERSION=	0.8.19
PORTREVISION=	2
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Extension of the NetworkX Python package for graphs
WWW=		https://github.com/dwavesystems/dwave-networkx

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>=0.12.5:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.4:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.17.3:math/py-numpy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist unittest

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems
GH_PROJECT=	dwave-graphs

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 0.8.19: Ran 270 tests in 35.034s (OK, skipped=14)

.include <bsd.port.mk>
