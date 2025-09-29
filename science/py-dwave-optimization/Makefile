PORTNAME=	dwave-optimization
DISTVERSION=	0.6.6
CATEGORIES=	science python # quantum-computing
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Nonlinear models for industrial optimization problems
WWW=		https://github.com/dwavesystems/dwave-optimization

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}meson-python>=0.18.0:devel/meson-python@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	pep517 cython3 autoplist pytest

post-install:
	# strip binaries
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/optimization/_model${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/optimization/_utilities${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/optimization/libdwave-optimization.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/optimization/states${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/optimization/symbols${PYTHON_TAG}.so

.include <bsd.port.mk>
