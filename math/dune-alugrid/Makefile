PORTNAME=	dune-alugrid
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
PORTREVISION=	8
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
GL_TAGNAME=	ffd6cd15dc7092593c3d5827c2a2b43b81d7a32f

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

CXXFLAGS+=	-fsigned-char

.include <bsd.port.mk>
