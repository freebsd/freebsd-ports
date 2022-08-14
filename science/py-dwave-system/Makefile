PORTNAME=	dwave-system
DISTVERSION=	1.15.0
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: API for incorporating the D-Wave system as a sampler

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>0:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-cloud-client>=0.9.1,<0.11.0:science/py-dwave-cloud-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-networkx>0:science/py-dwave-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-preprocessing>0:science/py-dwave-preprocessing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-tabu>=0.4.2:science/py-dwave-tabu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}homebase>=1.0.0,<2.0.0:devel/py-homebase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}minorminer>=0.2.8,<0.3.0:math/py-minorminer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.0:math/py-networkx@${PY_FLAVOR} \
		${PYNUMPY}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.7+
USE_PYTHON=	distutils unittest # 1 test fails because the closed source dwave.drivers optional dependency is missing

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

NO_ARCH=	yes

post-install:
	# remove conflicting __init__.py, see https://github.com/dwavesystems/dwave-system/issues/462
	@${RM} -r \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/__init__.py \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/__pycache__

.include <bsd.port.mk>
