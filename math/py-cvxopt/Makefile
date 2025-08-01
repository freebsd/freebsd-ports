PORTNAME=	cvxopt
DISTVERSION=	1.3.2
PORTREVISION=	12
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python software for convex optimization
WWW=		https://github.com/cvxopt/cvxopt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libamd.so:math/suitesparse-amd \
		libblas.so:math/blas \
		libcholmod.so:math/suitesparse-cholmod \
		libcolamd.so:math/suitesparse-colamd \
		liblapack.so:math/lapack \
		libsuitesparseconfig.so:math/suitesparse-config \
		libumfpack.so:math/suitesparse-umfpack
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python localbase:ldflags cpe
#USE_GITHUB=	yes
USE_PYTHON=	pep517 autoplist

CPE_VENDOR=	cvxopt_project

CFLAGS+=	-I${LOCALBASE}/include/suitesparse

OPTIONS_DEFINE=		GSL FFTW GLPK DSDP
OPTIONS_DEFAULT=	GSL FFTW GLPK DSDP

GSL_DESC=		Build with GSL, the GNU scientific library
GSL_MAKE_ENV=		CVXOPT_BUILD_GSL=1
GSL_LIB_DEPENDS=	libgsl.so:math/gsl

FFTW_MAKE_ENV=		CVXOPT_BUILD_FFTW=1
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3

GLPK_DESC=		Build with GLPK, the linear programming solver
GLPK_MAKE_ENV=		CVXOPT_BUILD_GLPK=1
GLPK_LIB_DEPENDS=	libglpk.so:math/glpk

DSDP_DESC=		Build with DSDP, the interior-point method
DSDP_MAKE_ENV=		CVXOPT_BUILD_DSDP=1
DSDP_CFLAGS=		-I${LOCALBASE}/include/dsdp
DSDP_LIB_DEPENDS=	libdsdp.so:math/dsdp

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cvxopt/*.so

do-test: install
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
