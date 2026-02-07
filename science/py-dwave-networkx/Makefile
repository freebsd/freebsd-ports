PORTNAME=	dwave-networkx
DISTVERSION=	0.8.18
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Extension of the NetworkX Python package for graphs
WWW=		https://github.com/dwavesystems/dwave-networkx

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>=0.12.0:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=3.0:math/py-networkx@${PY_FLAVOR} \
		${PYNUMPY}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist unittest

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
