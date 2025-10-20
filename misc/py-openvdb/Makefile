PORTNAME=	openvdb
DISTVERSIONPREFIX=	v
DISTVERSION=	12.0.1
PORTREVISION=	2
CATEGORIES=	misc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tools for storage and manipulation of sparse volumetric data
WWW=		https://www.openvdb.org \
		https://github.com/AcademySoftwareFoundation/openvdb

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/../../../LICENSE

BUILD_DEPENDS=	nanobind>0:devel/nanobind \
		${PYNUMPY}
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libopenvdb.so:misc/openvdb \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	${PYNUMPY}

USES=		cmake compiler:c++17-lang localbase:ldflags python
USE_LDCONFIG=	yes
USE_PYTHON=	flavors pytest

USE_GITHUB=	yes
GH_ACCOUNT=	AcademySoftwareFoundation

CMAKE_ON=	USE_NUMPY OPENVDB_PYTHON_WRAP_ALL_GRID_TYPES
CMAKE_OFF=	OPENVDB_BUILD_PYTHON_UNITTESTS
CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD} \
		-DFREEBSD_PYTHON_VER=${PYTHON_VER}

WRKSRC_SUBDIR=	openvdb/openvdb/python

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

PLIST_FILES=	${PYTHON_SITELIBDIR}/openvdb${PYTHON_TAG}.so

do-test: # run an example, since the supplied test appears to be only for Windows
	@cd ${WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/example.py && \
		[ -f ${WRKSRC}/mygrids.vdb ] && \
		${ECHO} "Test has succeeded."

.include <bsd.port.mk>
