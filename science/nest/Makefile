PORTNAME=	nest
DISTVERSIONPREFIX=	v
DISTVERSION=	2.20.1
PORTREVISION=	1
CATEGORIES=	science biology # NEST is used in neuroscience

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simulator for spiking neural network models

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	https://github.com/nest/nest-simulator/issues/1205

LIB_DEPENDS=	libgsl.so:math/gsl \
		libltdl.so:devel/libltdl

USES=		cmake ncurses pkgconfig readline
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

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lang
.endif

.include <bsd.port.mk>
