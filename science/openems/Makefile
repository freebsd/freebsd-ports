PORTNAME=	openems
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.35-76
DISTVERSIONSUFFIX=	-gd4448fa
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electromagnetic field solver using the EC-FDTD method

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	upstream only supports amd64 and powerpc64

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libCSXCAD.so:cad/csxcad \
		libexpat.so:textproc/expat2 \
		libfparser-4.5.so:math/fparser \
		libhdf5.so:science/hdf5 \
		libpng16.so:graphics/png \
		libsz.so:science/libaec \
		libtiff.so:graphics/tiff \
		libtinyxml.so:textproc/tinyxml \
		libvtkCommonCore-9.1.so:math/vtk9

USES=		cmake jpeg pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thliebig
GH_PROJECT=	openEMS

CMAKE_ARGS=	-DVTK_DIR=${LOCALBASE}/lib/cmake/vtk-9.1 \
		-DLOCALBASE=${LOCALBASE}

CXXFLAGS+=	-I${LOCALBASE}/include/fparser # fparser.pc probably returns a wrong value

DATADIR=	${PREFIX}/share/openEMS

post-install:
	@${REINPLACE_CMD} -i '' -e 's|#!/bin/bash|#!/bin/sh|' ${STAGEDIR}${PREFIX}/bin/openEMS.sh

.include <bsd.port.mk>
