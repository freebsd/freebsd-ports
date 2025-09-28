PORTNAME=	dwave-system
DISTVERSION=	1.33.0
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: API for incorporating the D-Wave system as a sampler
WWW=		https://github.com/dwavesystems/dwave-system

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>=0.12.20:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-cloud-client>=0.12.0:science/py-dwave-cloud-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-networkx>=0.8.10:science/py-dwave-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-optimization>=0.6.6:science/py-dwave-optimization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-preprocessing>=0.5.0:science/py-dwave-preprocessing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-samplers>=1.0.0:science/py-dwave-samplers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}homebase>=1.0.0:devel/py-homebase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}minorminer>=0.2.19:math/py-minorminer@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.7.3:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils unittest autoplist # 1 test fails because the closed source dwave.drivers optional dependency is missing

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
