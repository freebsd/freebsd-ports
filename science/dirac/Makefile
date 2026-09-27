PORTNAME=	dirac
DISTVERSIONPREFIX=	v
DISTVERSION=	26.1
CATEGORIES=	science # chemistry
PKGNAMESUFFIX=	-quantum-chemistry-software
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}-Source

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program for atomic & molecular relativistic all-electron calculations
WWW=		https://www.diracprogram.org/doku.php \
		https://gitlab.com/dirac/dirac

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=		compilation fails: Error: Type mismatch in argument 'lu' at (1); passed INTEGER(8) to INTEGER(4) (and similar)

BUILD_DEPENDS=	gmake:devel/gmake
LIB_DEPENDS=	libblas.so:math/blas \
		libhdf5.so:science/hdf5 \
		liblapack.so:math/lapack
TEST_DEPENDS=	bash:shells/bash

USES=		cmake:noninja,testing fortran localbase:ldflags python shebangfix

USE_GITLAB=	yes

SHEBANG_FILES=	pam.in \
		utils/process_schema.py \
		utils/dirac_data.py \
		utils/merge_amf.py \
		src/gen1int/subtree/tools/runtest.sh

CMAKE_OFF=	ENABLE_EXATENSOR \
		ENABLE_PCMSOLVER # PCMSolver integration is broken, see https://gitlab.com/dirac/dirac/-/issues/33 and https://gitlab.com/dirac/dirac/-/issues/34
CMAKE_ARGS=	-DMKL_FLAG=off

CFLAGS+=	-DSYS_LINUX # see https://gitlab.com/dirac/dirac/-/issues/32
CXXFLAGS+=	-DSYS_LINUX
FFLAGS+=	-DSYS_LINUX -fallow-argument-mismatch # -fallow-argument-mismatch to fix build on i386, see https://gitlab.com/dirac/dirac/-/issues/36
LDFLAGS+=	-llapack -lblas

BINARY_ALIAS=	make=${GMAKE} \
		python=${PYTHON_CMD} \
		python3=${PYTHON_CMD}

.include <bsd.port.options.mk>

.if ${ARCH} == armv7 || ${ARCH} == powerpc64 || ${ARCH} == powerpc64le
CMAKE_ARGS+=	-DENABLE_STIELTJES:BOOL=OFF
.endif

# 2 tests are known to fail, see https://gitlab.com/dirac/dirac/-/issues/35

.include <bsd.port.mk>
