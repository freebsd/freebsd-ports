# $FreeBSD$

PORTNAME=	fleur
DISTVERSION=	0.27-3 # Release 3 of Version 0.27
PORTREVISION=	7
CATEGORIES=	science
MASTER_SITES=	http://www.flapw.de/pm/uploads/FLEUR/
DISTNAME=	fleurMaXR${DISTVERSION:C/.*-//}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	FLAPW code for atomic computations in quantum chemistry and physics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		cmake:noninja fortran gnome localbase:ldflags tar:tgz
USE_GNOME=	libxml2

FFLAGS=		-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=		HDF5 MPI SCALAPACK ELPA WANNIER
OPTIONS_DEFAULT=	MPI SCALAPACK ELPA WANNIER

HDF5_CONFIGURE_ENV=	FLEUR_USE_HDF5=1 HDF5_ROOT=${LOCALBASE}/lib
HDF5_CONFIGURE_ENV_OFF=	FLEUR_USE_HDF5=0
HDF5_CMAKE_ON=		-DHDF5_INCLUDE_DIRS=${LOCALBASE}/include
HDF5_LDFLAGS=		-lhdf5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_BROKEN=		Missing hdf5.mod in hdf5

MPI_CONFIGURE_ENV=	FLEUR_USE_MPI=1
MPI_CONFIGURE_ENV_OFF=	FLEUR_USE_MPI=0
MPI_LDFLAGS=		-lmpich -lmpifort
MPI_LIB_DEPENDS=	libmpich.so:net/mpich
MPI_PLIST_FILES=	bin/fleur_MPI

SCALAPACK_DESC=		Use the ScaLAPACK Scalable LAPACK library
SCALAPACK_CMAKE_BOOL=	FREEBSD_USE_SCALAPACK
SCALAPACK_LDFLAGS=	-lscalapack
SCALAPACK_LIB_DEPENDS=	libscalapack.so:math/scalapack
SCALAPACK_IMPLIES=	MPI

ELPA_DESC=		Use libelpa, Eigenvalue SoLver for Petaflop Applications
ELPA_CMAKE_BOOL=	FREEBSD_USE_ELPA
ELPA_VARS=		FFLAGS+=-I${LOCALBASE}/include/elpa-2018.05.001/modules
ELPA_LDFLAGS=		-lelpa
ELPA_LIB_DEPENDS=	libelpa.so:math/elpa
ELPA_IMPLIES=		MPI

WANNIER_DESC=		Use Wannier library
WANNIER_CONFIGURE_ENV=	FLEUR_USE_WANNIER=1
WANNIER_CONFIGURE_ENV_OFF=	FLEUR_USE_WANNIER=0
WANNIER_LDFLAGS=	-lwannier
WANNIER_LIB_DEPENDS=	libwannier.so:science/wannier90

PLIST_FILES=	bin/fleur \
		bin/inpgen

.include <bsd.port.mk>
