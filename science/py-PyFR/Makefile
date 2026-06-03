PORTNAME=	PyFR
DISTVERSION=	3.1
PORTREVISION=	2
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyfr-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for solving advection-diffusion type problems
WWW=		https://www.pyfr.org/ \
		https://github.com/PyFR/PyFR

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gimmik>=3.2.1:math/py-gimmik@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.10:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=1.0.0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpi4py>=3.1.0:net/py-mpi4py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2.2.0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytools>=2016.2.1:devel/py-pytools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rtree>=1.0.1:devel/py-rtree@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	distutils concurrent autoplist pytest

SHEBANG_FILES=	setup.py pyfr/__main__.py

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/pyfr/tests

OPTIONS_MULTI=		PARALLEL
OPTIONS_MULTI_PARALLEL=	OPENCL OPENMP # CUDA isn't supported on FreeBSD
OPTIONS_DEFAULT=	${OPTIONS_MULTI_PARALLEL}
PARALLEL_DESC=		Parallelization backends to install

OPENCL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyopencl>0:devel/py-pyopencl@${PY_FLAVOR} \
			clblas>0:math/clblas
OPENMP_RUN_DEPENDS=	libxsmm>0:math/libxsmm

pre-build: # patch in pre-build to make the patch less error-prone (it has %%LOCALBASE%%)
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/pyfr/backends/openmp/compiler.py

post-install: # workaround: https://groups.google.com/forum/#!topic/pyfrmailinglist/RNi_LcizGBo
	@${RM} ${STAGEDIR}${PREFIX}/__main__.py
	@${REINPLACE_CMD} 's|^${PREFIX}/__main__\.py||' ${_PYTHONPKGLIST}

# tests as of 3.1:
# Results (0.66s):
#          3 passed

.include <bsd.port.mk>
