PORTNAME=	penaltymodel
DISTVERSION=	1.3.0
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Utilities and interfaces for using penalty models
WWW=		https://docs.ocean.dwavesys.com/projects/penaltymodel/en/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>=0.12.13:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}homebase>=1.0.1:devel/py-homebase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=3.0:math/py-networkx@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.7.3:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils cython autoplist unittest

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

NO_ARCH=	yes

.include <bsd.port.mk>
