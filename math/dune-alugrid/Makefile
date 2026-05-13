PORTNAME=	dune-alugrid
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: grid implementation providing simplex or cube grids
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vc>0:devel/vc
LIB_DEPENDS=	libalberta_utilities.so:math/alberta \
		libdunecommon.so:math/dune-common \
		libdunegeometry.so:math/dune-geometry \
		libdunegrid.so:math/dune-grid \
		libduneuggrid.so:math/dune-uggrid \
		libmetis.so:math/metis \
		libmpi.so:net/openmpi \
		libopenblas.so:math/openblas \
		libtbb.so:devel/onetbb

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	extensions
GL_TAGNAME=	3c17086ab906a35dbf290298d8d17b30452cc773

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

PORTDOCS=	*

CXXFLAGS+=	-fsigned-char

CMAKE_OFF=	DUNE_ENABLE_PYTHONBINDINGS

PLIST_SUB+= DUNE_ALUGRID_CMAKE_HASH=f482fe07d6e3bed36f1da49df98fc850

.include <bsd.port.mk>
