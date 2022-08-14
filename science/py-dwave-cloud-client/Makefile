PORTNAME=	dwave-cloud-client
DISTVERSION=	0.4.0
CATEGORIES=	science python www # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: REST interface to communicate with D-Wave Solver API servers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.7:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dimod>=0.10.5:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}diskcache>=5.2.1:devel/py-diskcache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-networkx>=0.8.9:science/py-dwave-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}homebase>=1.0.0:devel/py-homebase@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}plucky>=0.4.3:devel/py-plucky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.7.3:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-mock>0:www/py-requests-mock@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.7+
USE_PYTHON=	distutils cython autoplist unittest # 1 test fail, probably due to devel/py-homebase issues

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
