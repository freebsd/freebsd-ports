PORTNAME=	dwave-neal
DISTVERSION=	0.6.0.dev0
CATEGORIES=	science graphics # quantum-computing
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Simulated annealing sampler for general Ising model graphs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>0:science/py-dimod@${PY_FLAVOR} \
		${PYNUMPY}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.7+
USE_PYTHON=	distutils autoplist unittest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

do-test:
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/example.py

.include <bsd.port.mk>
