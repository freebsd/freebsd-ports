PORTNAME=	dune-pdelab
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0.20251127
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: PDE solver toolbox
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DUNE_DEPENDS=	dune-common>0:math/dune-common \
		dune-functions>0:math/dune-functions \
		dune-grid>0:math/dune-grid \
		dune-istl>0:math/dune-istl \
		dune-geometry>0:math/dune-geometry \
		dune-localfunctions>0:math/dune-localfunctions \
		dune-typetree>0:math/dune-typetree
BUILD_DEPENDS=	${DUNE_DEPENDS} \
		suitesparse>0:math/suitesparse \
		openmpi>0:net/openmpi
LIB_DEPENDS=	libarpack.so:math/arpack-ng@openmpi \
		libdunealugrid.so:math/dune-alugrid \
		libduneuggrid.so:math/dune-uggrid \
		libgmp.so:math/gmp \
		libmetis.so:math/metis \
		libpsurface.so:math/psurface \
		libopenblas.so:math/openblas \
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
RUN_DEPENDS=	${DUNE_DEPENDS} \
		suitesparse>0:math/suitesparse \
		openmpi>0:net/openmpi

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	pdelab
GL_TAGNAME=	91238f3936c949921259d1d47f84fa2ffec0e07d

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DTBB_INCLUDE_DIR=${LOCALBASE}/include -DTBB_LIBRARIES=${LOCALBASE}/lib/libtbb.so \
		-DCMAKE_DISABLE_FIND_PACKAGE_Alberta=ON

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

PORTDOCS=	*

CMAKE_OFF=	DUNE_ENABLE_PYTHONBINDINGS

PLIST_SUB+=	DUNE_PDELAB_CMAKE_HASH=108cfc623fc53aa07b4a3befb4d03117

.include <bsd.port.mk>
