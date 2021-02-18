# $FreeBSD$

PORTNAME=	cvxopt
DISTVERSION=	1.2.6
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python software for convex optimization

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack \
		libumfpack.so:math/suitesparse

USES=		python:3.6+ localbase:ldflags
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist

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

.include <bsd.port.mk>
