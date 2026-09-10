PORTNAME=	petiga
DISTVERSION=	g20250403
CATEGORIES=	math python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for High Performance Isogeometric Analysis
WWW=		https://github.com/dalcinl/PetIGA

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

LIB_DEPENDS=	libblas.so:math/blas \
		libblis.so:math/blis \
		liblapack.so:math/lapack \
		libmetis.so:math/metis \
		libmpich.so:net/mpich \
		libpetsc.so:science/PETSc

USES=		gmake compiler:c++14-lang fortran xorg
USE_LDCONFIG=	yes
USE_XORG=	x11

MAKEFILE=	makefile

MAKE_ENV=	PETSC_DIR=${LOCALBASE}
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	dalcinl
GH_PROJECT=	PetIGA
GH_TAGNAME=	cc362e1

TEST_TARGET=	check

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpetiga.so

.include <bsd.port.mk>
