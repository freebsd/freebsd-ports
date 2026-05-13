PORTNAME=	dune-grid-glue
DISTVERSION=	2.11.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: infrastructure for coupling of unrelated Dune grids
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2

BUILD_DEPENDS=	alberta-fem>0:math/alberta \
		openmpi>0:net/openmpi \
		psurface>0:math/psurface \
		vc>0:devel/vc
LIB_DEPENDS=	libdunecommon.so:math/dune-common \
		libdunegeometry.so:math/dune-geometry \
		libdunegrid.so:math/dune-grid \
		libduneuggrid.so:math/dune-uggrid \
		libopenblas.so:math/openblas \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	alberta-fem>0:math/alberta # binaries aren't linked with alberta, instead users' binaries are linked with it
RUN_DEPENDS+=	psurface>0:math/psurface

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	extensions
GL_TAGNAME=	89cb14b358e59cb0e8c335969e59d91309be8cf1

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DTBB_INCLUDE_DIR=${LOCALBASE}/include -DTBB_LIBRARIES=${LOCALBASE}/lib/libtbb.so

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

PORTDOCS=	*

CMAKE_OFF=	DUNE_ENABLE_PYTHONBINDINGS

PLIST_SUB+= DUNE_GRID_GLUE_CMAKE_HASH=bce1743c4fbd1bb094500b140dbd675f

.include <bsd.port.mk>
