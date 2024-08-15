PORTNAME=	cardioid
PORTVERSION=	g20211026
PORTREVISION=	3
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cardiac simulation toolkit
WWW=		https://github.com/LLNL/cardioid

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:testing shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_TAGNAME=	2f66d9f
GH_TUPLE=	mfem:mfem:v4.4:mfem

SHEBANG_FILES=	elec/compileReaction.template

CMAKE_TESTING_ON=	ENABLE_TESTS

PLIST_FILES=	bin/cardioid \
		bin/compileReaction \
		bin/singleCell

OPTIONS_DEFINE=		MFEM OPENMP
OPTIONS_SINGLE=		MFEM MPI
OPTIONS_SINGLE_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH OPENMP
OPTIONS_SUB=		yes

MFEM_DESC=		Build with MFEM mesh library
MFEM_CMAKE_ON=		-DMFEM_DIR=${WRKSRC_mfem}
MFEM_BROKEN=		see https://github.com/LLNL/cardioid/issues/15

NOMPI_DESC=		Build without parallel processing support
NOMPI_BROKEN=		https://github.com/LLNL/axom/issues/913

MPICH_USES=		mpi:mpich
MPICH_CMAKE_ON=		-DENABLE_MPI=ON

OPENMPI_USES=		mpi:openmpi
OPENMPI_CMAKE_ON=	-DENABLE_MPI=ON

OPENMP_CMAKE_BOOL=	ENABLE_OPENMP
OPENMP_BROKEN_OFF=	https://github.com/LLNL/cardioid/issues/14

.include <bsd.port.options.mk>

.if (!exists(/usr/include/omp.h) && ${PORT_OPTIONS:MOPENMP})
USES+=	compiler:gcc-c++11-lib
.else
USES+=	compiler:c++11-lang
.endif

.include <bsd.port.mk>
