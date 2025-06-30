PORTNAME=	qmcpack
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.0
PORTREVISION=	3
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Many-body ab initio Quantum Monte Carlo code for quantum chemistry
WWW=		https://www.qmcpack.org/ \
		https://github.com/QMCPACK/qmcpack

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	undefined reference to `__atomic_load'
.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfftw3.so:math/fftw3 \
		libhdf5.so:science/hdf5 \
		libmpich.so:net/mpich \
		libopenblas.so:math/openblas \
		libsz.so:science/libaec
TEST_DEPENDS=	bash:shells/bash

USES=		cmake:testing compiler:c++17-lang fortran gnome localbase:ldflags pkgconfig python shebangfix
USE_GNOME=	libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tu}

SHEBANG_FILES=	src/QMCTools/gpaw4qmcpack.py \
		${NEXUS_PLIST_FILES:C/^/nexus\//}
SHEBANG_GLOB=	check.sh

CMAKE_OFF=	BUILD_UNIT_TESTS
CMAKE_ARGS=	-DFREEBSD_PYTHON_VER=${PYTHON_VER}
CMAKE_TESTING_ON=	BUILD_UNIT_TESTS # many tests fail, see https://github.com/QMCPACK/qmcpack/issues/4274

PROGS=		convert4qmc convertpw4qmc gpaw4qmcpack.py ppconvert qmc-check-affinity qmc-extract-eshdf-kvectors qmc-get-supercell qmcfinitesize qmcpack qmcpack.settings
PLIST_FILES=	${PROGS:C/^/bin\//}

BINARY_ALIAS=	python=${PYTHON_CMD} python3=${PYTHON_CMD}

OPTIONS_DEFINE=		NEXUS
OPTIONS_DEFAULT=	NEXUS
OPTIONS_SUB=		yes

NEXUS_DESC=		Install Nexus (workflow utility) alongside QMCPACK
NEXUS_CMAKE_BOOL=	INSTALL_NEXUS
NEXUS_PY_DEPENDS=	${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyscf>0:science/py-pyscf@${PY_FLAVOR}
NEXUS_BUILD_DEPENDS=	${NEXUS_PY_DEPENDS}
NEXUS_RUN_DEPENDS=	${NEXUS_PY_DEPENDS}
NEXUS_PLIST_FILES=	bin/eshdf \
			bin/nxs-redo \
			bin/nxs-sim \
			bin/nxs-test \
			bin/qdens \
			bin/qdens-radial \
			bin/qmc-fit \
			bin/qmca

.include <bsd.port.mk>
