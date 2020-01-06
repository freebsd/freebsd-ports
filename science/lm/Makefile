# $FreeBSD$

PORTNAME=	lm
DISTVERSION=	2.3.0
DISTVERSIONSUFFIX=	-src
PORTREVISION=	9
CATEGORIES=	science
MASTER_SITES=	http://scs.illinois.edu/schulten/${PORTNAME}/download/${PORTNAME}${DISTVERSION:R:S/.//}/
PKGNAMESUFFIX=	-uiuc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software for sampling trajectories of the reaction-diffusion equations

BROKEN=		unfetchable

LICENSE=	UIUC_OPEN_SOURCE_LICENSE
LICENSE_NAME=	University of Illinois Open Source License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

BUILD_DEPENDS=	swig3.0:devel/swig30
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libprotobuf.so:devel/protobuf \
		libsz.so:science/szip

USES=		compiler:c++11-lang gettext-runtime gmake

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
CXXFLAGS+=	-DLINUX
MAKE_ENV=	BUILD_DIR=${WRKSRC} PROTOBUF_DIR=${LOCALBASE}
USE_CXXSTD=	c++11

OPTIONS_DEFINE=		MPI PYTHON VMD
OPTIONS_DEFAULT=	MPI PYTHON # VMD can't be default because VMD requires manual tarball fetch
OPTIONS_SUB=		yes

MPI_USES=		fortran
MPI_VARS=		XUSE_MPI=1
MPI_VARS_OFF=		XUSE_MPI=0
MPI_LIB_DEPENDS=	libmpich.so:net/mpich

PYTHON_USES=		python
PYTHON_VARS=		XUSE_PYTHON=1
PYTHON_VARS_OFF=	XUSE_PYTHON=0
PYTHON_CXXFLAGS=	-I${PYTHON_SITELIBDIR}/numpy/core/include
PYTHON_BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy/core/include/numpy/arrayobject.h:math/py-numpy@${PY_FLAVOR}

VMD_DESC=		Build the VMD plugin
VMD_VARS_OFF=		XUSE_VMD=0
VMD_VARS=		XUSE_VMD=1 VMD_ARCH=${ARCH:S/amd64/FREEBSDAMD64/:S/${ARCH}/FREEBSD/}
VMD_BUILD_DEPENDS=	${LOCALBASE}/vmd/plugins/${VMD_ARCH}/molfile/libmolfile_plugin.h:science/vmd
VMD_PLIST_SUB=		VMD_ARCH=${VMD_ARCH}

post-patch:
	@${CP} ${WRKSRC}/docs/config/local.mk.linux ${WRKSRC}/local.mk
	@${REINPLACE_CMD} -i '' ' \
		s|USE_MPI := 0|USE_MPI := ${XUSE_MPI}|; \
		s|USE_PYTHON := 1|USE_PYTHON := ${XUSE_PYTHON}|; \
		s|USE_VMD := 1|USE_VMD := ${XUSE_VMD}|; \
		s|USE_CUDA := 1|USE_CUDA := 0|; \
		s|swig|swig3.0|; \
		s|/usr/local|${LOCALBASE}|; \
		s|INSTALL_PREFIX := /opt/lm|INSTALL_PREFIX := ${STAGEDIR}${PREFIX}|; \
		s|BUILD_DIR := Build-linux|BUILD_DIR := Build-freebsd|; \
		s|CCFLAGS := -m64 -O2|CCFLAGS := $$(CXXFLAGS)|; \
		s|gcc|${CC}|; \
		s|g++|${CXX}|; \
		s| -lrt||' \
		${WRKSRC}/local.mk

post-patch-MPI-on:
	@${REINPLACE_CMD} -i '' ' \
		s|MPI_COMPILE_FLAGS = .*|MPI_COMPILE_FLAGS =|; \
		s|MPI_LINK_FLAGS = .*|MPI_LINK_FLAGS = -lmpich ${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so|' \
		${WRKSRC}/local.mk

post-patch-PYTHON-on:
	@${REINPLACE_CMD} -i '' 's|python-config|${PYTHON_CMD}-config|' ${WRKSRC}/local.mk

post-patch-VMD-on:
	@${REINPLACE_CMD} -i '' 's|LINUXAMD64|${VMD_ARCH}|' ${WRKSRC}/local.mk

.include <bsd.port.mk>
