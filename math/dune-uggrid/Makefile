# $FreeBSD$

PORTNAME=	dune-uggrid
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0rc2
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: The UG Grid Manager

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL-2.1

BUILD_DEPENDS=	openmpi>0:net/openmpi \
		vc>0:devel/vc
LIB_DEPENDS=	libdunecommon.so:math/dune-common \
		libopenblas.so:math/openblas \
		libtbb.so:devel/tbb
RUN_DEPENDS=	openmpi>0:net/openmpi

USES=		cmake compiler:c++17-lang fortran pkgconfig python
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	staging
GL_COMMIT=	1fce83c6efe2e0f77d0ee1b3cf6335172f1ace37

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
