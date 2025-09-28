PORTNAME=	dwave-hybrid
DISTVERSION=	0.6.14
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Hybrid asynchronous decomposition sampler prototype framework
WWW=		https://docs.ocean.dwavesys.com/projects/hybrid/en/stable/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>5:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dimod>=0.12.2:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-cloud-client>=0.10.6:science/py-dwave-cloud-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-networkx>=0.8.8:science/py-dwave-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-preprocessing>=0.5.4:science/py-dwave-preprocessing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-samplers>=1.0.0:science/py-dwave-samplers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-system>=1.16.0:science/py-dwave-system@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}minorminer>=0.1.7:math/py-minorminer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plucky>=0.4.3:devel/py-plucky@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.9+
USE_PYTHON=	distutils autoplist unittest # several tests fail, see https://github.com/dwavesystems/dwave-hybrid/issues/276

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
