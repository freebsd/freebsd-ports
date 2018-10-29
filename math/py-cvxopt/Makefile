# $FreeBSD$

PORTNAME=	cvxopt
DISTVERSION=	1.2.2
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python software for convex optimization

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack \
		libumfpack.so:math/suitesparse

USES=		python localbase:ldflags
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist

CFLAGS+=	-I${LOCALBASE}/include/suitesparse

OPTIONS_DEFINE=		WITH_GSL WITH_FFTW WITH_GLPK WITH_DSDP
OPTIONS_DEFAULT=	WITH_GSL WITH_FFTW WITH_GLPK WITH_DSDP

WITH_GSL_DESC=		Build with gsl
WITH_GSL_MAKE_ENV=	CVXOPT_BUILD_GSL=1
WITH_GSL_LIB_DEPENDS=	libgsl.so:math/gsl

WITH_FFTW_DESC=		Build with fftw
WITH_FFTW_MAKE_ENV=	CVXOPT_BUILD_FFTW=1
WITH_FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3

WITH_GLPK_DESC=		Build with GLPK
WITH_GLPK_MAKE_ENV=	CVXOPT_BUILD_GLPK=1
WITH_GLPK_LIB_DEPENDS=	libglpk.so:math/glpk

WITH_DSDP_DESC=		Build with DSDP
WITH_DSDP_MAKE_ENV=	CVXOPT_BUILD_DSDP=1
WITH_DSDP_CFLAGS=	-I${LOCALBASE}/include/dsdp
WITH_DSDP_LIB_DEPENDS=	libdsdp.so:math/dsdp

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cvxopt/*.so

.include <bsd.port.mk>
