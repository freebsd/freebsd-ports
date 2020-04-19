# $FreeBSD$

PORTNAME=	dune-alugrid
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: grid implementation providing simplex or cube grids

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vc>0:devel/vc
LIB_DEPENDS=	libdunecommon.so:math/dune-common \
		libdunegeometry.so:math/dune-geometry \
		libdunegrid.so:math/dune-grid \
		libmetis.so:math/metis \
		libmpi.so:net/openmpi

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	extensions
GL_COMMIT=	9cec115318adc7c3f4faa16a626f61996710c533

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

.include <bsd.port.mk>
