PORTNAME=	dwave-samplers
DISTVERSION=	1.0.0.dev1
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Classical algorithms for solving binary quadratic models

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>0:science/py-dimod@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}reno>0:textproc/py-reno@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils cython unittest

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
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/samplers -name "*${PYTHON_EXT_SUFFIX}.so" | ${XARGS} ${STRIP_CMD}

post-test:
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/example.py

.include <bsd.port.mk>
