PORTNAME=	votca
DISTVERSIONPREFIX=	v
DISTVERSION=	2025
PORTREVISION=	2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CSG and XTP: libraries for atomistic simulations
WWW=		https://www.votca.org/ \
		https://github.com/votca/votca

LICENSE=	APACHE20

BROKEN_i386=		undefined reference to `__atomic_load' # '

PY_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}ase>0:science/py-ase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>0:devel/py-xmltodict@${PY_FLAVOR} \
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
		libsz.so:science/libaec \
		libxc.so:science/libxc
RUN_DEPENDS=	bash:shells/bash \
		${PYNUMPY} \
		${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		cmake compiler:c++14-lang eigen:3 perl5 pkgconfig python:run \
		shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.sh *.pl *.py
SHEBANG_FILES=	csg/scripts/csg_call csg/scripts/csg_inverse \
		tools/scripts/votca_compare tools/scripts/votca_help2doc \
		xtp/scripts/xtp_update_mapfile xtp/scripts/xtp_basisset xtp/share/benchmark/xtp_benchmark xtp/scripts/xtp_autogen_mapping \
		xtp/scripts/xtp_modify_jobfile \
		xtp/scripts/xtp_qmmm2qm

CXXFLAGS+=	-DBOOST_TIMER_ENABLE_DEPRECATED

CMAKE_ON=	BUILD_XTP \
		CMAKE_DISABLE_FIND_PACKAGE_SPHINX
CMAKE_OFF=	INJECT_MARCH_NATIVE
CMAKE_ARGS=	-DLOCALBASE=${LOCALBASE} -DPython_EXECUTABLE=${PYTHON_CMD}

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=		APPS
OPTIONS_DEFAULT=	APPS
OPTIONS_SUB=		yes

APPS_DESC=		Build applications
APPS_CMAKE_BOOL=	INSTALL_CSGAPPS

post-install: # workaround for https://github.com/votca/votca/issues/1173
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/python.

do-test: # several tests fail, see https://github.com/votca/votca/issues/1098
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DENABLE_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

# tests as of 2025: 100% tests passed, 0 tests failed out of 250

.include <bsd.port.mk>
