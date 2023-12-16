PORTNAME=	dune-grid
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
PORTREVISION=	10
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: Geometry transformations, reference elements, etc
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	alberta-fem>0:math/alberta \
		openmpi>0:net/openmpi \
		psurface>0:math/psurface \
		vc>0:devel/vc
LIB_DEPENDS=	libdunecommon.so:math/dune-common \
		libdunegeometry.so:math/dune-geometry \
		libduneuggrid.so:math/dune-uggrid \
		libopenblas.so:math/openblas \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	alberta-fem>0:math/alberta # binaries aren't linked with alberta, instead users' binaries are linked with it
RUN_DEPENDS+=	psurface>0:math/psurface

USES=		cmake compiler:c++17-lang fortran pkgconfig python:build
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	core
GL_TAGNAME=	de36e4b4e99da4cd7a120a39779345e701821115

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DTBB_INCLUDE_DIR=${LOCALBASE}/include -DTBB_LIBRARIES=${LOCALBASE}/lib/libtbb.so

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

.include <bsd.port.mk>
