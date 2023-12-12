PORTNAME=	dune-grid-glue
DISTVERSION=	2.8.0
PORTREVISION=	8
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
GL_TAGNAME=	22efb0e3cbf0a75094a8d81a4fdd352c98e78947

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DTBB_INCLUDE_DIR=${LOCALBASE}/include -DTBB_LIBRARIES=${LOCALBASE}/lib/libtbb.so

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

.include <bsd.port.mk>
