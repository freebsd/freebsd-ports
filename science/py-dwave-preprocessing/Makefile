PORTNAME=	dwave-preprocessing
DISTVERSION=	0.6.10
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Preprocessing tools to aid in solving binary quadratic models
WWW=		https://github.com/dwavesystems/dwave-preprocessing

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>=0.12.6:science/py-dimod@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>=0.12.20:science/py-dimod@${PY_FLAVOR} \
		${PYNUMPY}

USES=		localbase:ldflags python
USE_PYTHON=	cython3 distutils unittest # 1 test fails, see https://github.com/dwavesystems/dwave-preprocessing/issues/74

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

.include <bsd.port.mk>
