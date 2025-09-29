PORTNAME=	dwave-ocean-sdk
DISTVERSION=	9.0.0
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Meta-package for D-Wave's Ocean tools
WWW=		https://docs.ocean.dwavesys.com/en/stable/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>=0.12.21:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-cloud-client>=0.14.0:science/py-dwave-cloud-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-gate>=0.3.4:science/py-dwave-gate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-hybrid>=0.6.14:science/py-dwave-hybrid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-inspector>=0.5.5:science/py-dwave-inspector@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-networkx>=0.8.18:science/py-dwave-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-optimization>=0.6.4:science/py-dwave-optimization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-preprocessing>=0.6.10:science/py-dwave-preprocessing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-samplers>=1.6.0:science/py-dwave-samplers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-system>=1.33.0:science/py-dwave-system@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}minorminer>=0.2.19:math/py-minorminer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}penaltymodel>=1.3.0:science/py-penaltymodel@${PY_FLAVOR}
		#${PYTHON_PKGNAMEPREFIX}pyqubo>=1.4.0:science/py-pyqubo@${PY_FLAVOR} # exclude pyqubo until it supports py312
BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	pep517 autoplist unittest

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
