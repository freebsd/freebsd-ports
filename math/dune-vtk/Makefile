# $FreeBSD$

PORTNAME=	dune-vtk
DISTVERSION=	g20201220
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: File reader and writer for the VTK XML format

LICENSE=	GPLv2+

HPP_DEPENDS=	${LOCALBASE}/include/dune/foamgrid/foamgrid.hh:math/dune-foamgrid \
		dune-localfunctions>0:math/dune-localfunctions \
		dune-spgrid>0:math/dune-spgrid
BUILD_DEPENDS=	${HPP_DEPENDS} \
		dune-functions>0:math/dune-functions \
		${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi
LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		libdunealugrid.so:math/dune-alugrid \
		libdunecommon.so:math/dune-common \
		libdunegeometry.so:math/dune-geometry \
		libdunegrid.so:math/dune-grid \
		libdunepolygongrid.so:math/dune-polygongrid \
		libugL.so:math/dune-uggrid \
		libgmp.so:math/gmp \
		libmetis.so:math/metis \
		libopenblas.so:math/openblas \
		libsuitesparseconfig.so:math/suitesparse \
		libsuperlu.so:math/superlu \
		libtbb.so:devel/tbb
RUN_DEPENDS=	${HPP_DEPENDS} \
		${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	extensions
GL_COMMIT=	847c3e5d0e5ff48ac3aad14adf6218b6578599af

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=		DOCS

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

.include <bsd.port.mk>
