PORTNAME=	openems
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.35-71
DISTVERSIONSUFFIX=	-g4c24b6e
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electromagnetic field solver using the EC-FDTD method

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libCSXCAD.so:cad/csxcad \
		libfparser-4.5.so:math/fparser \
		libhdf5.so:science/hdf5 \
		libsz.so:science/szip \
		libtinyxml.so:textproc/tinyxml \
		libvtkCommonCore-9.0.so:math/vtk9

USES=		cmake pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thliebig
GH_PROJECT=	openEMS

CXXFLAGS+=	-I${LOCALBASE}/include/fparser # fparser.pc probably returns a wrong value

DATADIR=	${PREFIX}/share/openEMS

post-install:
	@${REINPLACE_CMD} -i '' -e 's|#!/bin/bash|#!/bin/sh|' ${STAGEDIR}${PREFIX}/bin/openEMS.sh

.include <bsd.port.mk>
