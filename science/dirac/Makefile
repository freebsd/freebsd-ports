PORTNAME=	dirac
DISTVERSION=	22.0
PORTREVISION=	1
CATEGORIES=	science # chemistry
MASTER_SITES=	https://zenodo.org/record/6010450/files/
PKGNAMESUFFIX=	-quantum-chemistry-software
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}-Source

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program for atomic & molecular relativistic all-electron calculations
WWW=		http://diracprogram.org/doku.php

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails: Error: Old-style type declaration REAL*16 not supported at (1)
BROKEN_i386=	error: Type mismatch in argument 'dsetid' at (1); passed INTEGER(8) to INTEGER(4), see https://gitlab.com/dirac/dirac/-/issues/36

BUILD_DEPENDS=	gmake:devel/gmake
LIB_DEPENDS=	libblas.so:math/blas \
		libhdf5.so:science/hdf5 \
		liblapack.so:math/lapack

USES=		cmake:noninja,testing fortran localbase:ldflags python shebangfix

#USE_GITLAB=	yes
#GL_TAGNAME=	37b755410d9fdcd9b5e7bba6e43ceb7d5c7b9dae

SHEBANG_FILES=	pam.in \
		utils/process_schema.py \
		utils/dirac_data.py

CMAKE_OFF=	ENABLE_EXATENSOR \
		ENABLE_PCMSOLVER # PCMSolver integration is broken, see https://gitlab.com/dirac/dirac/-/issues/33 and https://gitlab.com/dirac/dirac/-/issues/34
CMAKE_ARGS=	-DMKL_FLAG=off

CFLAGS+=	-DSYS_LINUX # see https://gitlab.com/dirac/dirac/-/issues/32
CXXFLAGS+=	-DSYS_LINUX
FFLAGS+=	-DSYS_LINUX
LDFLAGS+=	-llapack -lblas

BINARY_ALIAS=	make=${GMAKE} \
		python=${PYTHON_CMD} \
		python3=${PYTHON_CMD}

# 2 tests are known to fail, see https://gitlab.com/dirac/dirac/-/issues/35

.include <bsd.port.mk>
