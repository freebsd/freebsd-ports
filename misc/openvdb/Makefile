# $FreeBSD$

PORTNAME=	openvdb
DISTVERSIONPREFIX=	v
DISTVERSION=	6.1.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tools for the storage and manipulation of sparse volumetric data

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblosc.so:archivers/c-blosc \
		libboost_system.so:devel/boost-libs \
		libHalf.so:graphics/ilmbase \
		libtbb.so:devel/tbb

USES=		cmake compiler:c++11-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	AcademySoftwareFoundation
USE_LDCONFIG=	yes

CMAKE_OFF=	OPENVDB_CORE_STATIC

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_USES=		python:2.7 # 3.6 is broken: https://github.com/AcademySoftwareFoundation/openvdb/issues/427
PYTHON_CMAKE_BOOL=	OPENVDB_BUILD_PYTHON_MODULE
PYTHON_CMAKE_ON=	-DFREEBSD_PYTHON_VER:STRING=${PYTHON_VER} -DUSE_NUMPY:BOOL=ON
PYTHON_LIB_DEPENDS=	${PY_BOOST}
PYTHON_BUILD_DEPENDS=	${PYNUMPY}
PYTHON_RUN_DEPENDS=	${PYNUMPY}

.include <bsd.port.mk>
