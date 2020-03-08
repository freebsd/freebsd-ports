# $FreeBSD$

PORTNAME=	PyFR
DISTVERSION=	1.9.0
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	http://www.pyfr.org/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for solving advection-diffusion type problems

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gimmik>=2.0:math/py-gimmik@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.6:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=1.0.0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpi4py>=2.0:net/py-mpi4py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytools>=2016.2.1:devel/py-pytools@${PY_FLAVOR} \
		${NUMPY}

USES=		python:3.3+ shebangfix zip
SHEBANG_FILES=	setup.py pyfr/__main__.py
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

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

.include <bsd.port.mk>
