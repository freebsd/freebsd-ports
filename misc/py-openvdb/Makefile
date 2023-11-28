PORTNAME=	openvdb
DISTVERSIONPREFIX=	v
DISTVERSION=	10.0.1
PORTREVISION=	2
CATEGORIES=	misc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tools for storage and manipulation of sparse volumetric data
WWW=		https://www.openvdb.org/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/../../../LICENSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	${PY_BOOST} \
		libboost_iostreams.so:devel/boost-libs \
		libopenvdb.so:misc/openvdb \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	${PYNUMPY}

USES=		cmake compiler:c++17-lang localbase:ldflags python
USE_LDCONFIG=	yes
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	AcademySoftwareFoundation

CMAKE_ON=	USE_NUMPY OPENVDB_PYTHON_WRAP_ALL_GRID_TYPES
CMAKE_OFF=	OPENVDB_BUILD_PYTHON_UNITTESTS
CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD}

WRKSRC_SUBDIR=	openvdb/openvdb/python

PLIST_FILES=	include/openvdb/python/pyopenvdb.h \
		${PYTHON_SITELIBDIR}/pyopenvdb.so

.include <bsd.port.mk>
