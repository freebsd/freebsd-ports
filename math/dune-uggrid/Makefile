PORTNAME=	dune-uggrid
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: The UG Grid Manager

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL-2.1

BUILD_DEPENDS=	openmpi>0:net/openmpi \
		vc>0:devel/vc
LIB_DEPENDS=	libdunecommon.so:math/dune-common \
		libopenblas.so:math/openblas \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	openmpi>0:net/openmpi

USES=		cmake compiler:c++17-lang fortran pkgconfig python
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	staging
GL_COMMIT=	bc2d1229420367563410ce9e519f5ff82b45266f

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DTBB_INCLUDE_DIR=${LOCALBASE}/include -DTBB_LIBRARIES=${LOCALBASE}/lib/libtbb.so

.include <bsd.port.mk>
