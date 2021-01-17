# $FreeBSD$

PORTNAME=	dune-polygongrid
DISTVERSION=	g20200214
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: 2D polygonal grid

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi
LIB_DEPENDS=	libdunecommon.so:math/dune-common \
		libdunegeometry.so:math/dune-geometry \
		libdunegrid.so:math/dune-grid \
		libugL.so:math/dune-uggrid \
		libopenblas.so:math/openblas \
		libtbb.so:devel/tbb
RUN_DEPENDS=	${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	extensions
GL_COMMIT=	608b915a7c6e7aed072a3d54745699a87e085d51

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
