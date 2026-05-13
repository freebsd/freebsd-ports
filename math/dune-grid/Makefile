PORTNAME=	dune-grid
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: Geometry transformations, reference elements, etc
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	psurface>0:math/psurface \
		vc>0:devel/vc
LIB_DEPENDS=	libdunecommon.so:math/dune-common \
		libdunegeometry.so:math/dune-geometry \
		libduneuggrid.so:math/dune-uggrid \
		libmpi.so:net/openmpi \
		libopenblas.so:math/openblas \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	psurface>0:math/psurface

USES=		cmake compiler:c++17-lang fortran pkgconfig python:build
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	core
GL_TAGNAME=	360045cbc742b79b29ec4c583dbe5560eb066ac0

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	DUNE_ENABLE_PYTHONBINDINGS
CMAKE_ARGS=	-DTBB_INCLUDE_DIR=${LOCALBASE}/include -DTBB_LIBRARIES=${LOCALBASE}/lib/libtbb.so \
		-DCMAKE_DISABLE_FIND_PACKAGE_Alberta=ON

PLIST_SUB+=	DUNE_GRID_CMAKE_HASH=bbddf3311de4ff25f44ffec0dbf3dda4

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

PORTDOCS=	*

.include <bsd.port.mk>
