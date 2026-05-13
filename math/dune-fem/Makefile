PORTNAME=	dune-fem
DISTVERSION=	2.10.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: Finite Element Methods, Finite Volume Methods, etc
WWW=		https://www.dune-project.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	arpack++>0:math/arpack++ \
		dune-istl>=2.6:math/dune-istl \
		dune-localfunctions>=2.6:math/dune-localfunctions \
		dune-spgrid>0:math/dune-spgrid \
		vc>0:devel/vc \
		openmpi>0:net/openmpi
LIB_DEPENDS=	libpsurface.so:math/psurface \
		libarpack.so:math/arpack-ng@openmpi \
		libdunealugrid.so:math/dune-alugrid \
		libdunecommon.so:math/dune-common \
		libdunegeometry.so:math/dune-geometry \
		libdunegrid.so:math/dune-grid \
		libdunepolygongrid.so:math/dune-polygongrid \
		libduneuggrid.so:math/dune-uggrid \
		libgmp.so:math/gmp \
		libmetis.so:math/metis \
		libopenblas.so:math/openblas \
		libsuitesparseconfig.so:math/suitesparse-config \
		libsuperlu.so:math/superlu \
		libamd.so:math/suitesparse-amd \
		libcamd.so:math/suitesparse-camd \
		libccolamd.so:math/suitesparse-ccolamd \
		libcholmod.so:math/suitesparse-cholmod \
		libcolamd.so:math/suitesparse-colamd \
		libldl.so:math/suitesparse-ldl \
		libspqr.so:math/suitesparse-spqr \
		libumfpack.so:math/suitesparse-umfpack \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	dune-istl>=2.6:math/dune-istl \
		dune-localfunctions>=2.6:math/dune-localfunctions \
		dune-spgrid>0:math/dune-spgrid \
		openmpi>0:net/openmpi

USES=		cmake compiler:c++17-lang eigen:3 fortran pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	dune-fem
GL_TAGNAME=	4cef5c6f2f8de83d690b351b5a6752fac268cda6

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	DUNE_ENABLE_PYTHONBINDINGS DUNE_REQUIRE_PYTHONBINDINGS

OPTIONS_DEFINE=		DOCS

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

PORTDOCS=	*

post-install: # https://gitlab.dune-project.org/dune-fem/dune-fem/-/issues/111
	${RM} ${STAGEDIR}${PREFIX}/share/dune/cmake/modules/FindPThreads.cmake
	${RM} ${STAGEDIR}${PREFIX}/share/dune/cmake/modules/FindSIONlib.cmake

PLIST_SUB+=	DUNE_FEM_CMAKE_HASH=86351963f06ada977b94a7a3e8733e31

.include <bsd.port.mk>
