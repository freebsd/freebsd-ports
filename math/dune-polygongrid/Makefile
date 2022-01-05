PORTNAME=	dune-polygongrid
DISTVERSION=	g20210307
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: 2D polygonal grid

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
GL_COMMIT=	f76933aa51aa3ae3e58a5705f9f7ce7d1f6c012c

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
