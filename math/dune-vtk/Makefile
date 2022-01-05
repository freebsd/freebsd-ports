PORTNAME=	dune-vtk
DISTVERSION=	g20210623
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: File reader and writer for the VTK XML format

LICENSE=	GPLv2+

HPP_DEPENDS=	${LOCALBASE}/include/dune/foamgrid/foamgrid.hh:math/dune-foamgrid \
		dune-localfunctions>0:math/dune-localfunctions \
		dune-spgrid>0:math/dune-spgrid
BUILD_DEPENDS=	${HPP_DEPENDS} \
		dune-functions>0:math/dune-functions \
		suitesparse>0:math/suitesparse \
		${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi
LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		libdunealugrid.so:math/dune-alugrid \
		libdunecommon.so:math/dune-common \
		libdunegeometry.so:math/dune-geometry \
		libdunegrid.so:math/dune-grid \
		libdunepolygongrid.so:math/dune-polygongrid \
		libduneuggrid.so:math/dune-uggrid \
		libgmp.so:math/gmp \
		libmetis.so:math/metis \
		libopenblas.so:math/openblas \
		libpsurface.so:math/psurface \
		libamd.so:math/suitesparse-amd \
		libcamd.so:math/suitesparse-camd \
		libccolamd.so:math/suitesparse-ccolamd \
		libcholmod.so:math/suitesparse-cholmod \
		libcolamd.so:math/suitesparse-colamd \
		libsuitesparseconfig.so:math/suitesparse-config \
		libldl.so:math/suitesparse-ldl \
		libspqr.so:math/suitesparse-spqr \
		libumfpack.so:math/suitesparse-umfpack \
		libsuperlu.so:math/superlu \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	${HPP_DEPENDS} \
		suitesparse>0:math/suitesparse \
		${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	extensions
GL_COMMIT=	38f79c23ef8f29210d41353a8380e42b78422f2f

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=		DOCS

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

.include <bsd.port.mk>
