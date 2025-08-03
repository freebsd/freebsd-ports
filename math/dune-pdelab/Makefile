PORTNAME=	dune-pdelab
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0.20210824
PORTREVISION=	30
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
		openmpi4>0:net/openmpi4
LIB_DEPENDS=	libarpack.so:math/arpack-ng \
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
		openmpi4>0:net/openmpi4

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	pdelab
GL_TAGNAME=	20c7085389d3eb4f8ca99e1bc60f7fa6036536c8

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DTBB_INCLUDE_DIR=${LOCALBASE}/include -DTBB_LIBRARIES=${LOCALBASE}/lib/libtbb.so

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

.include <bsd.port.mk>
