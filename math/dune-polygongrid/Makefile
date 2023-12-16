PORTNAME=	dune-polygongrid
DISTVERSION=	2.8.0
PORTREVISION=	8
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: 2D polygonal grid
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi
LIB_DEPENDS=	libdunecommon.so:math/dune-common \
		libdunegeometry.so:math/dune-geometry \
		libdunegrid.so:math/dune-grid \
		libduneuggrid.so:math/dune-uggrid \
		libopenblas.so:math/openblas \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	extensions
GL_TAGNAME=	90840c3d36f5fa6e18a00e7df7be01832cd7e23b

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
