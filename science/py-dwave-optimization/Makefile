PORTNAME=	dwave-optimization
DISTVERSION=	0.7.2
CATEGORIES=	science python # quantum-computing
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Nonlinear models for industrial optimization problems
WWW=		https://github.com/dwavesystems/dwave-optimization

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meson-python>0:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21.3:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.21.3:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>=0.12.21:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.6.0:science/py-scikit-learn@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython pep517 pytest

PYTEST_BROKEN_TESTS=	test_simple_inputs

post-install:
	# strip binaries
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/optimization/_model${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/optimization/_utilities${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/optimization/libdwave-optimization.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/optimization/states${PYTHON_TAG}.so

pre-test:
	@cd ${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/optimization && \
		${FIND} . -name '*.so' -exec ${CP} {} ${WRKSRC}/dwave/optimization/{} \;

# tests as of 0.7.2: 869 passed, 1 broken in 3.23s

# all C++ patches are workaround for https://github.com/dwavesystems/dwave-optimization/issues/595

.include <bsd.port.mk>
