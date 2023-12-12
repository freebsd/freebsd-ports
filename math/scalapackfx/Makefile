PORTNAME=	scalapackfx
DISTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern Fortran wrappers around ScaLAPACK routines
WWW=		https://github.com/dftbplus/scalapackfx

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	fypp:devel/py-fypp@${PY_FLAVOR}
LIB_DEPENDS=	libmpi.so:net/mpich \
		libmpifort.so:net/mpich \
		libopenblas.so:math/openblas \
		libscalapack.so:math/scalapack

USES=		cmake fortran python:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dftbplus

CMAKE_ARGS=	-DSCALAPACK_LIBRARY=${LOCALBASE}
LDFLAGS+=	-lscalapack

CMAKE_ON=	BUILD_SHARED_LIBS

do-test:
	@cd ${WRKSRC}/test && mpirun -n 2 ${BUILD_WRKSRC}/test/test_det

.include <bsd.port.mk>
