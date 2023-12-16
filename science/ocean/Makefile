PORTNAME=	ocean
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	science
PKGNAMESUFFIX=	-spectroscopy-code

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	BSE code for core spectroscopy
WWW=		https://github.com/times-software/OCEAN

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libopenblas.so:math/openblas
RUN_DEPENDS=	abinit>0:science/abinit \
		quantum-espresso>0:science/quantum-espresso

USES=		fortran gmake localbase perl5 shebangfix
USE_PERL5=	build run

SHEBANG_GLOB=	*.pl

USE_GITHUB=	yes
GH_ACCOUNT=	times-software
GH_PROJECT=	${PORTNAME:tu}

MAKE_ARGS=	MPIFC=${MPIFC} \
		MPI_HOME=${MPI_HOME} \
		MPI_LIBS="${MPI_LIBS}"

BINARY_ALIAS=	make=${GMAKE}

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	OPENMPI

MPICH_USES=		mpi:mpich

OPENMPI_USES=		mpi:openmpi

post-extract:
	# copy in the Makefile.arch file
	@${LN} -s ${FILESDIR}/Makefile.arch ${WRKSRC}/
	# set execution flag on all *.pl files
	@${FIND} ${WRKSRC} -name "*.pl" | ${XARGS} ${CHMOD} +x

post-patch:
	# patch the bash path (but run_examples.pl is currently dysfunctional, according to README)
	@${REINPLACE_CMD} -i '' -e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|' ${WRKSRC}/EXAMPLE/run_examples.pl

post-install:
	# strip binaries
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*.x

.include <bsd.port.mk>
