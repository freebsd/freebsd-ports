PORTNAME=	nest
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	science biology # NEST is used in neuroscience

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simulator for spiking neural network models

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	https://github.com/nest/nest-simulator/issues/1205

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libgsl.so:math/gsl \
		libltdl.so:devel/libltdl
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:testing ncurses pkgconfig python readline shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_PROJECT=	nest-simulator

SHEBANG_FILES=	extras/nest-server extras/nest-server-mpi testsuite/do_tests.sh

OPTIONS_DEFINE=		PYTHON DOCS
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_CMAKE_BOOL=	BUILD_PYTHON
PYTHON_USE=		python=cython
PYTHON_CMAKE_ON=	-DCYTHON_EXECUTABLE:STRING=${PREFIX}/bin/cython-${PYTHON_VER}

PORTDOCS=		*

# 2 tests are known to fail, see https://github.com/nest/nest-simulator/issues/2190
# tests require the port to be installed with DOCS=ON, see https://github.com/nest/nest-simulator/issues/2191

post-install:
	@${REINPLACE_CMD} -i '' -e 's|^python3 |${PYTHON_CMD} |' ${STAGEDIR}${PREFIX}/share/nest/testsuite/do_tests.sh

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lang
.endif

.include <bsd.port.mk>
