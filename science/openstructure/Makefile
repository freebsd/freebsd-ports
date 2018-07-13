# $FreeBSD$

PORTNAME=	openstructure
DISTVERSION=	1.7.1
PORTREVISION=	3
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Molecular modelling and visualization environment

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	fftw3>0:math/fftw3
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libfftw3f.so:math/fftw3-float \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff \
		${PY_BOOST}
RUN_DEPENDS=	${PYNUMPY} \
		bash:shells/bash

USES=		cmake:outsource eigen:3 python pyqt:4 qt:4 shebangfix
USE_GITLAB=	yes
GL_SITE=	https://git.scicore.unibas.ch/
GL_ACCOUNT=	schwede
GL_COMMIT=	${DISTVERSION}
SHEBANG_FILES=	scripts/dng.in scripts/ost.in scripts/ost_config.in
USE_QT=		corelib gui network opengl xml qmake_build moc_build rcc_build uic_build
USE_PYQT=	core gui
USE_GL=		gl glu
USE_LDCONFIG=	yes

BINARY_ALIAS=	python=${PYTHON_CMD}
CMAKE_ARGS=	-DPYTHON_INCLUDE_PATH=${PYTHON_INCLUDEDIR} \
		-DPYTHON_LIBRARIES=${PYTHON_LIBDIR} \
		-DFREEBSD_BOOST_PYTHON_COMPONENT=python${PYTHON_VER:S/.//} \
		-DFREEBSD_PYTHON_LIBRARY=python${PYTHON_VER} \
		-DCMAKE_CXX_FLAGS='-std=c++98' # c++98 is needed until 1.8.0 to prevent C++ code build breakage

post-extract:
	@${MV} ${WRKSRC}-* ${WRKSRC}

.include <bsd.port.mk>
