# $FreeBSD$

PORTNAME=	dune-fem
DISTVERSION=	2.6.0rc3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: Finite Element Methods, Finite Volume Methods, etc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	arpack++>0:math/arpack++ \
		dune-istl>=2.6:math/dune-istl \
		dune-localfunctions>=2.6:math/dune-localfunctions \
		dune-spgrid>0:math/dune-spgrid \
		vc>0:devel/vc \
		${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi
LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		libdunealugrid.so:math/dune-alugrid \
		libdunecommon.so:math/dune-common \
		libdunegeometry.so:math/dune-geometry \
		libdunegrid.so:math/dune-grid \
		libugS2.so:math/dune-uggrid \
		libmetis.so:math/metis \
		libopenblas.so:math/openblas \
		libtbb.so:devel/tbb
RUN_DEPENDS=	dune-istl>=2.6:math/dune-istl \
		dune-localfunctions>=2.6:math/dune-localfunctions \
		dune-spgrid>0:math/dune-spgrid \
		${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi

USES=		cmake compiler:c++17-lang eigen:3 fortran pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	dune-fem
GL_COMMIT=	d1b565ab01047e44508c23bb9ba3e3b4491cd8a7

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=		DOCS

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

post-install: # https://gitlab.dune-project.org/dune-fem/dune-fem/-/issues/111
	${RM} ${STAGEDIR}${PREFIX}/share/dune/cmake/modules/FindPThreads.cmake
	${RM} ${STAGEDIR}${PREFIX}/share/dune/cmake/modules/FindSIONlib.cmake

.include <bsd.port.mk>
