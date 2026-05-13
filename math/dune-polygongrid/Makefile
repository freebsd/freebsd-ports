PORTNAME=	dune-polygongrid
DISTVERSION=	2.11.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: 2D polygonal grid
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	openmpi>0:net/openmpi
LIB_DEPENDS=	libdunecommon.so:math/dune-common \
		libdunegeometry.so:math/dune-geometry \
		libdunegrid.so:math/dune-grid \
		libduneuggrid.so:math/dune-uggrid \
		libopenblas.so:math/openblas \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	openmpi>0:net/openmpi

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	extensions
GL_TAGNAME=	384fb60ba711c68409135a2c0c718b50885d6f3f

CMAKE_ON=	BUILD_SHARED_LIBS

CMAKE_OFF=	DUNE_ENABLE_PYTHONBINDINGS

PLIST_SUB+= DUNE_POLYGONGRID_CMAKE_HASH=a5790b9ea7ab4c1cc0d4b7b04aa78f6b

.include <bsd.port.mk>
