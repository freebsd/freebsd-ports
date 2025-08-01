PORTNAME=	dune-vtk
DISTVERSION=	2.8.0
PORTREVISION=	27
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: File reader and writer for the VTK XML format
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2+

HPP_DEPENDS=	${LOCALBASE}/include/dune/foamgrid/foamgrid.hh:math/dune-foamgrid \
		dune-localfunctions>0:math/dune-localfunctions \
		dune-spgrid>0:math/dune-spgrid
BUILD_DEPENDS=	${HPP_DEPENDS} \
		dune-functions>0:math/dune-functions \
		suitesparse>0:math/suitesparse \
		openmpi4>0:net/openmpi4
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
		openmpi4>0:net/openmpi4

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	extensions
GL_TAGNAME=	467838cde3bbea3d27d2bd117570a3215240dcd1

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=		DOCS

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

.include <bsd.port.mk>
