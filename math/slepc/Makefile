PORTNAME=	slepc
DISTVERSION=	3.22.2
PORTREVISION=	2
CATEGORIES=	math devel
MASTER_SITES=	http://slepc.upv.es/download/distrib/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable Library for Eigenvalue Problem Computations
WWW=		http://slepc.upv.es/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libblas.so:math/blas \
		libblis.so:math/blis \
		liblapack.so:math/lapack \
		libmetis.so:math/metis \
		libmpich.so:net/mpich \
		libpetsc.so:science/PETSc

USES=		gmake fortran python shebangfix xorg
USE_XORG=	x11 # not really needed, but is inherited from the PETSc setup
USE_LDCONFIG=	yes

SHEBANG_FILES=	configure
SHEBANG_GLOB=	*.py

MAKEFILE=	makefile
MAKE_ENV=	PETSC_DIR=${LOCALBASE} PETSC_ARCH="" SLEPC_DIR=${WRKSRC} PYTHON=${PYTHON_CMD}

TEST_TARGET=	test # 1 of 2568 tests fail because some file can't be opened

BINARY_ALIAS=	python=${PYTHON_CMD}

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./configure --prefix=${PREFIX}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libslepc.so.${PORTVERSION}

.include <bsd.port.mk>
