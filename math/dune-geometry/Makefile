PORTNAME=	dune-geometry
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
PORTREVISION=	10
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: Geometry transformations, reference elements, etc
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	openmpi>0:net/openmpi \
		vc>0:devel/vc
LIB_DEPENDS=	libdunecommon.so:math/dune-common \
		libopenblas.so:math/openblas \
		libtbb.so:devel/onetbb

USES=		cmake compiler:c++17-lang fortran pkgconfig python
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	core
GL_TAGNAME=	e7bfb66e48496aa28e47974c33ea9a4579bf723b

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DTBB_INCLUDE_DIR=${LOCALBASE}/include -DTBB_LIBRARIES=${LOCALBASE}/lib/libtbb.so

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

.include <bsd.port.mk>
