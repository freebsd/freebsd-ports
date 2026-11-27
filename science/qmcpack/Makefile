PORTNAME=	qmcpack
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.0
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

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
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

SHEBANG_FILES=	nexus/manual_install \
		nexus/nexus/bin/eshdf \
		nexus/nexus/bin/nxs-redo \
		nexus/nexus/bin/nxs-sim \
		nexus/nexus/bin/nxs-test \
		nexus/nexus/bin/qdens \
		nexus/nexus/bin/qdens-radial \
		nexus/nexus/bin/qmc-fit \
		nexus/nexus/bin/qmca
SHEBANG_GLOB=	check.sh *.py

CMAKE_OFF=	BUILD_UNIT_TESTS \
		BUILD_MICRO_BENCHMARKS
CMAKE_ARGS=	-DFREEBSD_PYTHON_VER=${PYTHON_VER} \
		-DFREEBSD_USE_INTEGRATION_TESTING=ON \
		-DQMC_NO_SLOW_CUSTOM_TESTING_COMMANDS=ON
CMAKE_TESTING_ON=	BUILD_UNIT_TESTS

TEST_ENV=	${MAKE_ENV} PYTEST_ADDOPTS="--disable-plugin-autoload -p pytest_order"

PROGS=		convert4qmc convertpw4qmc gpaw4qmcpack.py ppconvert qmc-check-affinity qmc-extract-eshdf-kvectors qmc-get-supercell qmcfinitesize qmcpack qmcpack.settings

BINARY_ALIAS=	python=${PYTHON_CMD} python3=${PYTHON_CMD}

OPTIONS_DEFINE=		NEXUS
OPTIONS_DEFAULT=	NEXUS
OPTIONS_SUB=		yes

NEXUS_DESC=		Install Nexus (workflow utility) alongside QMCPACK
NEXUS_CMAKE_BOOL=	QMC_INSTALL_NEXUS
NEXUS_PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyscf>0:science/py-pyscf@${PY_FLAVOR}
NEXUS_BUILD_DEPENDS=	${NEXUS_PY_DEPENDS}
NEXUS_RUN_DEPENDS=	${NEXUS_PY_DEPENDS}

# tests as of 4.4.0: 100% tests passed, 0 tests failed out of 129

.include <bsd.port.mk>
