# $FreeBSD$

PORTNAME=	nest
DISTVERSIONPREFIX=	v
DISTVERSION=	2.18.0
PORTREVISION=	3
CATEGORIES=	science biology # NEST is used in neuroscience

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	ba8feb49570f1118e2896191ebae790e8feca3d8.diff:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simulator for spiking neural network models

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	https://github.com/nest/nest-simulator/issues/1205

LIB_DEPENDS=	libgsl.so:math/gsl \
		libltdl.so:devel/libltdl \
		libomp.so:devel/openmp

USES=		cmake compiler:c++11-lang ncurses pkgconfig readline
USE_GITHUB=	yes
GH_PROJECT=	nest-simulator
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		PYTHON DOCS
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_CMAKE_BOOL=	BUILD_PYTHON
PYTHON_USES=		python
PYTHON_USE=		python=cython
PYTHON_CMAKE_ON=	-DCYTHON_EXECUTABLE:STRING=${PREFIX}/bin/cython-${PYTHON_VER}

PORTDOCS=		*

.include <bsd.port.mk>
