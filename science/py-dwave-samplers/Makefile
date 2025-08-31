PORTNAME=	dwave-samplers
DISTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Classical algorithms for solving binary quadratic models
WWW=		https://github.com/dwavesystems/dwave-samplers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>=0.12.13:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.6.3:math/py-networkx@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}reno>0:textproc/py-reno@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR}

USES=		python
USE_PYTHON=	cython3 distutils unittest # 2 tests fail, see https://github.com/dwavesystems/dwave-samplers/issues/66

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	# fix file paths, workaround for https://github.com/dwavesystems/dwave-samplers/issues/31
	@cd ${STAGEDIR}${PYTHON_SITELIBDIR} && ( \
		for f in `${FIND} samplers -name "*.so"`; do \
			${MV} $$f dwave/$$f; \
		done; \
		${RM} -r samplers; \
	)
	# strip binaries
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/samplers -name "*${PYTHON_TAG}.so" | ${XARGS} ${STRIP_CMD}
	# remove conflicting __init__.py, see https://github.com/dwavesystems/dwave-system/issues/462
	@${RM} -r \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/__init__.py \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/__pycache__

post-test:
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/example.py

.include <bsd.port.mk>
