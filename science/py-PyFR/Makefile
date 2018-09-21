# $FreeBSD$

PORTNAME=	PyFR
DISTVERSION=	1.7.6
CATEGORIES=	science python
MASTER_SITES=	http://www.pyfr.org/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for solving advection-diffusion type problems

LICENSE=	BSD3CLAUSE
xLICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gimmik>=2.0:math/py-gimmik@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.6:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=1.0.0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpi4py>=2.0:net/py-mpi4py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytools>=2016.2.1:devel/py-pytools@${PY_FLAVOR} \
		clblas>0:math/clblas \
		${NUMPY}

USES=		python:3.3+ shebangfix zip
SHEBANG_FILES=	setup.py pyfr/__main__.py
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

OPTIONS_MULTI=		MP
OPTIONS_MULTI_MP=	OPENCL OPENMP # CUDA isn't supported on FreeBSD
OPTIONS_DEFAULT=	${OPTIONS_MULTI_MP}
MP_DESC=		Parallelization backend to install

OPENCL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyopencl>0:devel/py-pyopencl@${PY_FLAVOR}
OPENMP_RUN_DEPENDS=	openmp>0:devel/openmp

post-install: # workaround: https://groups.google.com/forum/#!topic/pyfrmailinglist/RNi_LcizGBo
	@${RM} ${STAGEDIR}${PREFIX}/__main__.py
	@${REINPLACE_CMD} 's|^${PREFIX}/__main__\.py||' ${_PYTHONPKGLIST}

.include <bsd.port.mk>
