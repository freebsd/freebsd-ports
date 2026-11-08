PORTNAME=	dwave-preprocessing
DISTVERSION=	0.6.11
PORTREVISION=	2
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Preprocessing tools to aid in solving binary quadratic models
WWW=		https://github.com/dwavesystems/dwave-preprocessing

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>=0.12.21:science/py-dimod@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>=0.12.21:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21.6:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR}

USES=		localbase:ldflags python
USE_PYTHON=	cython distutils unittest

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	# strip binaries
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/preprocessing/cyfix_variables${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/preprocessing/presolve/cypresolve${PYTHON_TAG}.so
	# remove conflicting __init__.py, see https://github.com/dwavesystems/dwave-preprocessing/issues/45
	@${RM} -r \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/__init__.py \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/__pycache__

# tests as of 0.6.11: Ran 375 tests in 4.075s (OK)

.include <bsd.port.mk>
