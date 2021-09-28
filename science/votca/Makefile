PORTNAME=	votca
DISTVERSIONPREFIX=	v
DISTVERSION=	2021.2-18560
DISTVERSIONSUFFIX=	-gfbe18d971
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CSG and XTP: libraries for atomistic simulations

LICENSE=	APACHE20

BROKEN_i386=	undefined reference to `__atomic_load'

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		rdkit>0:science/rdkit
BUILD_DEPENDS=	bash:shells/bash \
		lmp:science/lammps \
		${PY_DEPENDS}
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libecpint.so:science/libecpint \
		libexpat.so:textproc/expat2 \
		libfftw3.so:math/fftw3 \
		libgromacs_d.so:science/gromacs \
		libhdf5.so:science/hdf5 \
		libint2.so:science/libint2 \
		libsz.so:science/szip \
		libxc.so:science/libxc
RUN_DEPENDS=	bash:shells/bash \
		${PYNUMPY} \
		${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		cmake compiler:c++14-lang eigen:3 perl5 pkgconfig python:run \
		shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TUPLE=	\
		votca:tools:9c102e0:tools/tools \
		votca:csg:da5c1dc:csg/csg \
		votca:xtp:2a31d70:xtp/xtp \
		votca:csg-tutorials:2b7b657:csg_tutorials/csg-tutorials \
		votca:xtp-tutorials:8576616:xtp_tutorials/xtp-tutorials

SHEBANG_GLOB=	*.sh *.pl *.py
SHEBANG_FILES=	csg/scripts/csg_call.in csg/scripts/csg_inverse.in \
		tools/scripts/votca_compare.in tools/scripts/votca_help2doc.in \
		xtp/scripts/xtp_update_mapfile.in xtp/scripts/xtp_basisset.in xtp/share/benchmark/xtp_benchmark.in xtp/scripts/xtp_autogen_mapping.in \
		xtp/scripts/xtp_qmmm2qm.in

CMAKE_ON=	BUILD_XTP
CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD}

OPTIONS_DEFINE=		APPS
OPTIONS_DEFAULT=	APPS
OPTIONS_SUB=		yes

APPS_DESC=		Build applications
APPS_CMAKE_BOOL=	BUILD_CSGAPPS

do-test: # 6 testscases are known to fail: https://github.com/votca/votca/issues/760
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DENABLE_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
