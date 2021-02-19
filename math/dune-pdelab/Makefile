# $FreeBSD$

PORTNAME=	dune-pdelab
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: PDE solver toolbox

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
		${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi
LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		libdunealugrid.so:math/dune-alugrid \
		libugL.so:math/dune-uggrid \
		libgmp.so:math/gmp \
		libmetis.so:math/metis \
		libopenblas.so:math/openblas \
		libsuitesparseconfig.so:math/suitesparse \
		libsuperlu.so:math/superlu \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	${DUNE_DEPENDS} \
		${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	pdelab
GL_COMMIT=	33aaa8e2e0598c98e17c3e38973307bee45858fb

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DTBB_INCLUDE_DIR=${LOCALBASE}/include -DTBB_LIBRARIES=${LOCALBASE}/lib/libtbb.so

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

.include <bsd.port.mk>
