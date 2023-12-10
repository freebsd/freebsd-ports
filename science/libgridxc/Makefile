PORTNAME=	libgridxc
DISTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	https://gitlab.com/siesta-project/libraries/${PORTNAME}/-/archive/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to compute the exchange and correlation energy and potentials
WWW=		https://gitlab.com/siesta-project/libraries/libgridxc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake fortran pkgconfig
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFINE=		LIBXC
OPTIONS_DEFAULT=	LIBXC MPICH
OPTIONS_SUB=		yes

NOMPI_DESC=		Build without parallel processing support

MPICH_USES=		mpi:mpich
MPICH_CMAKE_ON=		-DWITH_MPI=ON
MPICH_VARS=		FFLAGS+=-fallow-argument-mismatch

OPENMPI_USES=		mpi:openmpi
OPENMPI_CMAKE_ON=	-DWITH_MPI=ON
OPENMPI_VARS=		FFLAGS+=-fallow-argument-mismatch

LIBXC_DESC=		Use libxc for exchange-correlation functionals for DFT
LIBXC_CMAKE_BOOL=	WITH_LIBXC
LIBXC_VARS=		FCFLAGS+="-I${LOCALBASE}/include" LDFLAGS+="-L${LOCALBASE}/lib -lxcf90"
LIBXC_LIB_DEPENDS=	libxc.so:science/libxc

.include <bsd.port.mk>
